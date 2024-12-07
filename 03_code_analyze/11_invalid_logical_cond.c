#include <stdio.h>
#include <stdbool.h>

bool both_not_null(unsigned int a, unsigned int b) {
    if (a & b) {
        return true;
    }
    return false;
}

int main() {
    printf("both_is_null = %d\n", both_not_null(1, 2));
    return 0;
}
