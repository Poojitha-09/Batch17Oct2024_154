/*1. Using ternary operator compare 3 numbers and display the smallest number */


#include <stdio.h>

int main() {
    int num1, num2, num3;

    // Take input for three numbers
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Using ternary operator to find the smallest number
    int smallest = (num1 < num2) ? ( (num1 < num3) ? num1 : num3 ) : ( (num2 < num3) ? num2 : num3 );

    // Display the smallest number
    printf("The smallest number is: %d\n", smallest);

    return 0;
}
