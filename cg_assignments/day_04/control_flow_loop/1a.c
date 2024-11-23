/* 1. WAP to read a number n and to display the cumulative sum of factorial of all numbers upto n . (use for or while)
Input: 4
Ouput: 4!+3!+2!+1! = 32 */

#include <stdio.h>

// Function to compute factorial of a number
int factorial(int num) {
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n, sum = 0;

    // Read the number n
    printf("Enter a number: ");
    scanf("%d", &n);

    // Display the factorial sum
    printf("Output: ");
    for (int i = n; i >= 1; i--) {
        sum += factorial(i);
        if (i != n) {
            printf("+");
        }
        printf("%d!", i);
    }

    // Display the cumulative sum
    printf(" = %d\n", sum);

    return 0;
}
