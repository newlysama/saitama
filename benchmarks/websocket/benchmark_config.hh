#pragma once

#include <benchmark/benchmark.h>

#include "utils/websocket/websocket.hh"

constexpr const char* HOST = "stream.binance.com";
constexpr int PORT = 9443;
constexpr const char* PATH = "/ws/btcusdt@trade";

WebSocketClient client;
extern bool connected;