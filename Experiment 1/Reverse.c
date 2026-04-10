// C program to reverse a string using recursion
#include <stdio.h>
#include <string.h>

// Recursive function to reverse the string
void reverse(char str[], int start, int end) {
    if (start >= end)
        return;

    // Swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call
    reverse(str, start + 1, end - 1);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);

    reverse(str, 0, len - 1);

    printf("Reversed string: %s\n", str);

    return 0;
}