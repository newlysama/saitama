#include "websocket.hh"

WebSocketClient::WebSocketClient()
    : tls_initialized_(false), connected_(false) {
    mbedtls_net_init(&net_);
    mbedtls_ssl_init(&ssl_);
    mbedtls_ssl_config_init(&conf_);
    mbedtls_ctr_drbg_init(&ctr_drbg_);
    mbedtls_entropy_init(&entropy_);
    mbedtls_x509_crt_init(&cacert_);
}

WebSocketClient::~WebSocketClient() {
    close();
}

bool WebSocketClient::connect(const std::string& host, const std::string& port, const std::string& path) {
    const char* pers = "websocket_client";

    if (mbedtls_ctr_drbg_seed(&ctr_drbg_, mbedtls_entropy_func, &entropy_,
                              reinterpret_cast<const unsigned char*>(pers),
                              strlen(pers)) != 0) {
        return false;
    }

    if (mbedtls_net_connect(&net_, host.c_str(), port.c_str(), MBEDTLS_NET_PROTO_TCP) != 0) {
        return false;
    }

    if (mbedtls_ssl_config_defaults(&conf_,
                                    MBEDTLS_SSL_IS_CLIENT,
                                    MBEDTLS_SSL_TRANSPORT_STREAM,
                                    MBEDTLS_SSL_PRESET_DEFAULT) != 0) {
        return false;
    }

    mbedtls_ssl_conf_authmode(&conf_, MBEDTLS_SSL_VERIFY_NONE);
    mbedtls_ssl_conf_rng(&conf_, mbedtls_ctr_drbg_random, &ctr_drbg_);

    if (mbedtls_ssl_setup(&ssl_, &conf_) != 0) {
        return false;
    }

    mbedtls_ssl_set_bio(&ssl_, &net_, mbedtls_net_send, mbedtls_net_recv, nullptr);

    if (mbedtls_ssl_set_hostname(&ssl_, host.c_str()) != 0) {
        return false;
    }

    if (mbedtls_ssl_handshake(&ssl_) != 0) {
        return false;
    }

    std::string key = generateWebSocketKey();
    std::ostringstream req;
    req << "GET " << path << " HTTP/1.1\r\n"
        << "Host: " << host << "\r\n"
        << "Upgrade: websocket\r\n"
        << "Connection: Upgrade\r\n"
        << "Sec-WebSocket-Key: " << key << "\r\n"
        << "Sec-WebSocket-Version: 13\r\n\r\n";

    if (mbedtls_ssl_write(&ssl_,
                          reinterpret_cast<const unsigned char*>(req.str().c_str()),
                          req.str().length()) <= 0) {
        return false;
    }

    char buf[1024] = {0};
    int len = mbedtls_ssl_read(&ssl_, reinterpret_cast<unsigned char*>(buf), sizeof(buf) - 1);
    if (len <= 0) {
        return false;
    }

    std::string response(buf, len);
    if (response.find("101 Switching Protocols") == std::string::npos) {
        return false;
    }

    connected_ = true;
    return true;
}

bool WebSocketClient::sendText(const std::string& message) {
    if (!connected_) return false;

    std::vector<unsigned char> frame;
    frame.push_back(0x81); // FIN=1, OPCODE=1 (text)

    size_t len = message.size();
    if (len <= 125) {
        frame.push_back(static_cast<unsigned char>(0x80 | len)); // mask bit = 1
    } else if (len <= 65535) {
        frame.push_back(0x80 | 126);
        frame.push_back((len >> 8) & 0xFF);
        frame.push_back(len & 0xFF);
    } else {
        frame.push_back(0x80 | 127);
        for (int i = 7; i >= 0; --i)
            frame.push_back((len >> (8 * i)) & 0xFF);
    }

    // Generate 4-byte masking key
    std::array<unsigned char, 4> mask;
    for (auto& byte : mask) byte = static_cast<unsigned char>(rand() % 256);
    frame.insert(frame.end(), mask.begin(), mask.end());

    // Append masked payload
    for (size_t i = 0; i < len; ++i)
        frame.push_back(message[i] ^ mask[i % 4]);

    return mbedtls_ssl_write(&ssl_, frame.data(), frame.size()) > 0;
}

bool WebSocketClient::receiveText(std::string& out_message) {
    if (!connected_) {
        out_message.clear();
        return false;
    }

    unsigned char buf[2048] = {0};
    int len = mbedtls_ssl_read(&ssl_, buf, sizeof(buf));
    if (len <= 0) {
        out_message.clear();
        return false;
    }

    if ((buf[0] & 0x0F) == 0x1) { // text frame
        int payloadLen = buf[1] & 0x7F;
        int offset = 2;
        if (payloadLen == 126) offset += 2;
        else if (payloadLen == 127) offset += 8;
        out_message.assign(reinterpret_cast<char*>(buf + offset), len - offset);
        return true;
    }

    out_message.clear();
    return false;
}

void WebSocketClient::close() {
    if (connected_) {
        mbedtls_ssl_close_notify(&ssl_);
        connected_ = false;
    }

    mbedtls_net_free(&net_);
    mbedtls_ssl_free(&ssl_);
    mbedtls_ssl_config_free(&conf_);
    mbedtls_ctr_drbg_free(&ctr_drbg_);
    mbedtls_entropy_free(&entropy_);
    mbedtls_x509_crt_free(&cacert_);

    tls_initialized_ = false;
}

std::string WebSocketClient::generateWebSocketKey() {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 255);

    unsigned char key[16];
    for (int i = 0; i < 16; ++i) key[i] = static_cast<unsigned char>(dist(rd));

    unsigned char encoded[64];
    size_t olen = 0;
    mbedtls_base64_encode(encoded, sizeof(encoded), &olen, key, sizeof(key));
    return std::string(reinterpret_cast<char*>(encoded), olen);
}

