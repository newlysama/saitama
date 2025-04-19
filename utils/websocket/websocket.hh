#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <random>
#include <iomanip>
#include <cstring>
#include <array>
#include <mbedtls/ssl.h>
#include <mbedtls/net_sockets.h>
#include <mbedtls/ctr_drbg.h>
#include <mbedtls/entropy.h>
#include <mbedtls/x509_crt.h>
#include <mbedtls/base64.h>
#include <mbedtls/sha1.h>

#include <iostream>

class WebSocketClient {
    public:
        WebSocketClient();
        ~WebSocketClient();

        bool connect(const std::string& host, const std::string& port, const std::string& path = "/");
        bool sendText(const std::string& message);
        bool receiveText(std::string& out_message);
        void close();

    private:
        std::string generateWebSocketKey();

        bool tls_initialized_;

        mbedtls_net_context net_;
        mbedtls_entropy_context entropy_;
        mbedtls_ctr_drbg_context ctr_drbg_;
        mbedtls_ssl_context ssl_;
        mbedtls_ssl_config conf_;
        mbedtls_x509_crt cacert_;

        bool connected_ = false;
};
