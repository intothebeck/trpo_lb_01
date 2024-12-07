#include <stdlib.h>
#include <stdio.h>

double my_div(double a, double b) {
    return a / b;
}

int main() {
    double res = my_div(1, 0);
    fprintf(stderr, "res = %f\n", res);
    return 0;
}