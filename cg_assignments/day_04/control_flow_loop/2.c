/* Write a program to accept “N” integers from the user. “N” also has to be taken from the user. Take the count of +ve numbers, -ve numbers and 0’s.

However the program should not accept a non-integer value. If a non-integer value is entered, used must be asked to re-enter. */
#include <stdio.h>
int main() {
    int n, num;
    int positive_count = 0, negative_count = 0, zero_count = 0;

    // Get the number of inputs
    printf("Enter the number of integers: ");
    while (scanf("%d", &n) != 1) {
        printf("Invalid input! Please enter a valid integer for the number of integers: ");
        while (getchar() != '\n');  // Clear the input buffer
    }

    // Loop to take N integers
    for (int i = 0; i < n; i++) {
        printf("Enter integer %d: ", i + 1);

        // Check if the user entered a valid integer
        if (scanf("%d", &num) == 1) {
            if (num > 0) {
                positive_count++;
            } else if (num < 0) {
                negative_count++;
            } else {
                zero_count++;
            }
        } else {
            // Handle invalid input
            printf("Invalid input! Please enter a valid integer.\n");
            while (getchar() != '\n');  // Clear the input buffer
            i--; // Don't count this invalid input, ask for the input again
        }
    }

    // Output the counts of positive, negative, and zero numbers
    printf("\nPositive numbers: %d\n", positive_count);
    printf("Negative numbers: %d\n", negative_count);
    printf("Zero numbers: %d\n", zero_count);

    return 0;
}
