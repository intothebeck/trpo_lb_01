#include <stdio.h>
#include <stdlib.h>

int* create_array(int i) {
    return malloc(i * sizeof(int));
}

int main() {
    const int size = 5;
    int *a = create_array(size);
    for (int i = 0; i < size; i++) {
        a[i] = i;
    }

    printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
    return 0;
}
