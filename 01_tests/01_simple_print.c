#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    printf("2 + 2 = %d\n", add(2, 2));
    printf("1 + 4 = %d\n", add(1, 4));
    return 0;
}
