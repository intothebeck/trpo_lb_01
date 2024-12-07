#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a + b;
}

#define CHECK_IMPL(got, expected, line)                     \
    {                                                       \
    if ((got) != (expected)) {                              \
        fprintf(stderr, "Test failed on line %d\n", line);  \
        exit(EXIT_FAILURE);                                 \
    }                                                       \
    }                                                       \

#define CHECK(got, expected) CHECK_IMPL(got, expected, __LINE__)

int main() {
    CHECK(add(2, 2), 4);
    CHECK(add(1, 4), 5);

    return 0;
}
