#include <stdlib.h>
#include <stdio.h>

int handle_value(int a, int mode) {
    switch (mode) {
        case 1: a += 1;
        case 2: a += 2;
        default: a = 0;
    }
    return a;
}

int main() {
    int res = handle_value(2, 1);
    fprintf(stderr, "res = %d\n", res);
    return 0;
}