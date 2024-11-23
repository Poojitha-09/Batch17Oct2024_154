/*WAP to invoke functions below based on user input character using function pointer. Character mapping and respective functions to be invoked are given below.*/
#include <stdio.h>
// Function prototypes
int add(int x, int y);
int sub(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

int main() {
    int x, y, result;
    char operator;
    int (*operation)(int, int); // Function pointer declaration

    // Prompt the user to enter two integers and an operator
    printf("Enter first number: ");
    scanf("%d", &x);
    
    printf("Enter second number: ");
    scanf("%d", &y);
    
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator); // The space before %c is to consume any leftover newline character

    // Select the function based on the operator input using function pointer
    switch (operator) {
        case '+':
            operation = add;  // Point to add function
            break;
        case '-':
            operation = sub;  // Point to sub function
            break;
        case '*':
            operation = multiply;  // Point to multiply function
            break;
        case '/':
            operation = divide;  // Point to divide function
            break;
        default:
            printf("Invalid operator!\n");
            return 1;
    }

    // Invoke the selected function via function pointer
    result = operation(x, y);

    // Display the result
    printf("Result: %d\n", result);

    return 0;
}

// Function definitions
int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    if (y == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0;  // Return 0 for division by zero error
    }
    return x / y;
}
