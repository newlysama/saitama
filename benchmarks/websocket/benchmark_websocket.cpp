#include "benchmark_config.hh"

static void BM_WebSocket_ConnectAndReceive(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(connected);
        if (connected) {
            std::string message;
            bool ok = client.receiveText(message);
            benchmark::DoNotOptimize(ok);
            benchmark::DoNotOptimize(message);
        }
    }
}
BENCHMARK(BM_WebSocket_ConnectAndReceive);

static void BM_WebSocket_ReceiveOnly(benchmark::State& state) {
    benchmark::DoNotOptimize(connected);

    for (auto _ : state) {
        std::string message;
        bool ok = client.receiveText(message);
        benchmark::DoNotOptimize(ok);
        benchmark::DoNotOptimize(message);
    }
}
BENCHMARK(BM_WebSocket_ReceiveOnly);

static void BM_WebSocket_SendDummy(benchmark::State& state) {
    benchmark::DoNotOptimize(connected);

    std::string payload = R"({
        "method": "SUBSCRIBE",
        "params": ["btcusdt@depth"],
        "id": 42
    })";

    for (auto _ : state) {
        bool result = client.sendText(payload);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_WebSocket_SendDummy);
