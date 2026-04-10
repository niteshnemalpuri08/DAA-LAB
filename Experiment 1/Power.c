// C program to find the power of a number
#include <stdio.h>

int main() {
    int base, exponent, result = 1;

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter exponent: ");
    scanf("%d", &exponent);

    for(int i = 1; i <= exponent; i++) {
        result = result * base;
    }

    printf("Result = %d\n", result);

    return 0;
}