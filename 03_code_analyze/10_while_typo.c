#include <stdio.h>
#include <stdbool.h>

int main() {
    const int size = 5;
    int array[size] = {1, 2, 3, 4, 5};

    int i = 0;
    while (i < size) {
        printf("Value = %d\n", array[i]);
    }

    return 0;
}
