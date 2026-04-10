// C program to find the factorial of a number
#include <stdio.h>

int main() {
    int n, i;
    unsigned long long factorial = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Check for negative number
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } 
    else {
        for(i = 1; i <= n; i++) {
            factorial = factorial * i;
        }
        printf("Factorial of %d = %llu\n", n, factorial);
    }

    return 0;
}