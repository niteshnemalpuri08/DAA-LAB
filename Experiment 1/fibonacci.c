// C program to find the nth Fibonacci number
#include <stdio.h>

int main() {
    int n, first = 0, second = 1, next;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Fibonacci number = %d", first);
    } 
    else if (n == 1) {
        printf("Fibonacci number = %d", second);
    } 
    else {
        for (int i = 2; i <= n; i++) {
            next = first + second;
            first = second;
            second = next;
        }
        printf("Fibonacci number = %d", next);
    }

    return 0;
}