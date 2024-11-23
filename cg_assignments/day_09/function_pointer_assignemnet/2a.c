/* Extend Q1 to include a function below which will return the address of a function based on input character.

<address of function> getaddr(char mychar);*/


#include <stdio.h>
int add(int x, int y);
int sub(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);
int (*getaddr(char mychar))(int, int);
int main() {
    int x, y, result;
    char operator;
    int (*operation)(int, int); // Function pointer declaration
    printf("Enter first number: ");
    scanf("%d", &x);  
    printf("Enter second number: ");
    scanf("%d", &y);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator); // The space before %c is to consume any leftover newline character
    operation = getaddr(operator);

    if (operation == NULL) {
        printf("Invalid operator!\n");
        return 1;
    }

    result = operation(x, y);
    printf("Result: %d\n", result);

    return 0;
}
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
int (*getaddr(char mychar))(int, int) {
    switch (mychar) {
        case '+':
            return add;  // Return address of add function
        case '-':
            return sub;  // Return address of sub function
        case '*':
            return multiply;  // Return address of multiply function
        case '/':
            return divide;  // Return address of divide function
        default:
            return NULL;  // Return NULL for invalid operator
    }
}
