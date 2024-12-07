#include <stdlib.h>

void set_zero(int *v) {
    if (v == NULL) {
        *v = 0;
    }
}

int main() {
    int value = 5;
    set_zero(&value);
    set_zero(NULL);
    return 0;
}