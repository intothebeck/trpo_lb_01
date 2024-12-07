#include <stdio.h>

int main() {
    unsigned int counter = 10;

    while (counter >= 0) {
        printf("Counter: %u\n", counter);
        counter--;
    }

    return 0;
}
