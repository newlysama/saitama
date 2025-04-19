#include "benchmark_config.hh"
#include "benchmark_websocket.cpp"

bool connected;

int main(int argc, char** argv) {
    connected = client.connect(HOST, std::to_string(PORT), PATH);
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    return 0;
}   