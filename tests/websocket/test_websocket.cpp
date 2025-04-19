#include "test_config.hh"

class WebSocketClientTest : public ::testing::Test {
    protected:
    WebSocketClient client;
    
    void SetUp() override {
        ASSERT_TRUE(client.connect("stream.binance.com", "9443", "/ws/btcusdt@trade"));
    }
    
    void TearDown() override {
        client.close();
    }
};

TEST_F(WebSocketClientTest, T01_CanReceiveTradeData) {
    std::string message;
    ASSERT_TRUE(client.receiveText(message));
    
    // Vérifie que le message contient au moins un champ typique de Binance
    EXPECT_TRUE(message.find("\"e\":\"trade\"") != std::string::npos);
}

TEST_F(WebSocketClientTest, T02_ReceiveFailsWhenDisconnected) {
    client.close();
    
    std::string message;
    bool success = client.receiveText(message);
    EXPECT_FALSE(success);
    EXPECT_EQ(message, "");
}