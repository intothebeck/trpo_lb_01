#include <stdio.h>

int* createArray(int i) {
    int arr[5] = {1, 2, 3, 4, i};
    return arr;
}

int main() {
    const int size = 5;
    int *ptrs[size];
    for (int i = 0; i < size; i++) {
        ptrs[i] = createArray(i);
    }

    for (int i = 0; i < size; i++) {
        int *ptr = ptrs[i];
        printf("%d %d %d %d %d\n", ptr[0], ptr[1], ptr[2], ptr[3], ptr[4]);
    }
    return 0;
}
