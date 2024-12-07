#include <iostream>
#include <cmath>
#include <benchmark/benchmark.h>

constexpr int count = 40;

int fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int fibonacci_iterative(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fibonacci_recursive_sin(int n) {
    benchmark::DoNotOptimize(sin(n));
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int fibonacci_iterative_sin(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        benchmark::DoNotOptimize(sin(i));
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

static void BM_Fibonacci_Recursive(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(fibonacci_recursive(count));
    }
}
BENCHMARK(BM_Fibonacci_Recursive);

static void BM_Fibonacci_Iterative(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(fibonacci_iterative(count));
    }
}
BENCHMARK(BM_Fibonacci_Iterative);

static void BM_Fibonacci_Recursive_sin(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(fibonacci_recursive_sin(count));
    }
}
BENCHMARK(BM_Fibonacci_Recursive_sin);

static void BM_Fibonacci_Iterative_sin(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(fibonacci_iterative_sin(count));
    }
}
BENCHMARK(BM_Fibonacci_Iterative_sin);

BENCHMARK_MAIN();
