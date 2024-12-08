#include <stdio.h>
#include <time.h>
#include "stack.h"

#define ELEMENTS_COUNT 1000000  // Количество элементов для тестирования

void benchmarkPush() {
    Stack stack;
    initStack(&stack);

    clock_t start = clock();

    for (int i = 0; i < ELEMENTS_COUNT; i++) {
        push(&stack, i);
    }

    clock_t end = clock();
    double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken for %d push operations: %.6f seconds\n", ELEMENTS_COUNT, elapsedTime);

    destroyStack(&stack);
}

void benchmarkPop() {
    Stack stack;
    initStack(&stack);

    // Заполняем стек
    for (int i = 0; i < ELEMENTS_COUNT; i++) {
        push(&stack, i);
    }

    clock_t start = clock();

    for (int i = 0; i < ELEMENTS_COUNT; i++) {
        pop(&stack, NULL);
    }

    clock_t end = clock();
    double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken for %d pop operations: %.6f seconds\n", ELEMENTS_COUNT, elapsedTime);

    destroyStack(&stack);
}

int main() {
    printf("Benchmarking push operation:\n");
    benchmarkPush();

    printf("\nBenchmarking pop operation:\n");
    benchmarkPop();

    return 0;
}
