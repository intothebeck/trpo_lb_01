#include <stdio.h>
#include <stdbool.h>

bool check_value(int a) {
    if (a = 10) {
        return true;
    }
    return false;
}

int main() {
    int value = 3;

    printf("Value is ok? %d\n", check_value(value));

    return 0;
}
