//Write a program to check whether a given string is a palindrome. Ignore spaces and differences between uppercase and lowercase letters.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int left, right;
    int palindrome = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    left = 0;
    right = strlen(str) - 1;

    while (left < right) {

        while (left < right && !isalnum(str[left])) {
            left++;
        }

        while (left < right && !isalnum(str[right])) {
            right--;
        }

        if (tolower(str[left]) != tolower(str[right])) {
            palindrome = 0;
            break;
        }

        left++;
        right--;
    }

    if (palindrome)
        printf("Palindrome");
    else
        printf("Not a palindrome");

    return 0;
}
