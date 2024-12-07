#include <stdlib.h>
#include <stdio.h>

int inc(int v) {
    return v + 1;
}

int main() {
    int value;
    int res = inc(value);
    fprintf(stderr, "res = %d\n", value);
    return 0;
}