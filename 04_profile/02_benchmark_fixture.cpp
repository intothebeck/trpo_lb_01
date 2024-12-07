#include <benchmark/benchmark.h>
#include <string>

static void StringToNumberBenchmark(benchmark::State& state, const std::string& input_string) {
    for (auto _ : state) {
        auto number = std::stoll(input_string);
        benchmark::DoNotOptimize(number);
    }
}

class StringLengthFixture : public benchmark::Fixture {
public:
    void SetUp(const benchmark::State& state) override {
        input_string = std::string(state.range(0), '1');
    }

    void TearDown(const benchmark::State& state) override {}

    std::string input_string;
};

BENCHMARK_DEFINE_F(StringLengthFixture, StringToNumberBenchmark)(benchmark::State& state) {
    StringToNumberBenchmark(state, input_string);
}

BENCHMARK_REGISTER_F(StringLengthFixture, StringToNumberBenchmark)
    ->RangeMultiplier(2)
    ->Range(1, 16);

BENCHMARK_MAIN();
