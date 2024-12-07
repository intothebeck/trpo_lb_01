#include <stdlib.h>
#include <stdio.h>

int* function1(int* num) {
    *num += 10;
    return num;
}

int* function2(int* num) {
    *num -= 5;
    return num;
}

int* function3(int* num) {
    if (*num > 0) {
        *num *= 2;
    }
    return num;
}

int* function4(int* num) {
    if (*num != 0) {
        return 0;
    }
    return num;
}

int* function5(int* num) {
    *num /= 2;
    return num;
}

int* function6(int* num) {
    *num = *num * *num;
    return num;
}

int* function7(int* num) {
    if (*num > 3) {
        *num += 1;
        return num;
    }
    return num;
}

int* function8(int* num) {
    *num += 5;
    return num;
}

int* function9(int* num) {
    *num *= 25;
    return num;
}

int* function10(int* num) {
    if (*num > 0) {
        *num *= -1;
    } else {
        *num *= 10;
    }
    return num;
}

int* function11(int* num) {
    if (*num < 1) {
        *num = 3;
    } else {
        *num += 3;
    }

    int result = 0;
    for (int i = 1; i < *num; i++) {
        if (i & 1) {
            result += 1;
        }
    }
    *num = result;
    return num;
}

int main() {
    int number = 5;
    int* ptr = &number;

    int* ptr1 = function1(ptr);
    int* ptr2 = function2(ptr1);
    int* ptr3 = function3(ptr2);
    int* ptr4 = function4(ptr3);
    int* ptr5 = function5(ptr4);
    int* ptr6 = function6(ptr5);
    int* ptr7 = function7(ptr6);
    int* ptr8 = function8(ptr7);
    int* ptr9 = function10(ptr8);
    int* ptr10 = function10(ptr9);
    int* ptr11 = function11(ptr10);

    fprintf(stdout, "Result = %d\n", *ptr);
    return EXIT_SUCCESS;
}