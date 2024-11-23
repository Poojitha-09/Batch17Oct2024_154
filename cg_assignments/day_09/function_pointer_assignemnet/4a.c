/* 4. Extend Q1 to define an array of function pointers and invoke them based user input character*/
#include <stdio.h>
int add(int x, int y);
int sub(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);
int (*getaddr(char mychar))(int, int);
int invokefunc(int (*operation)(int, int), int val1, int val2);
int main() {
    int x, y, result;
    char operator;
    int (*operations[])(int, int) = {add, sub, multiply, divide};
    char operators[] = {'+', '-', '*', '/'};
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator); // The space before %c is to consume any leftover newline character
    int index = -1;
    for (int i = 0; i < 4; i++) {
        if (operators[i] == operator) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Invalid operator!\n");
        return 1;
    }
    printf("Enter first number: ");
    scanf("%d", &x); // Read first number
    printf("Enter second number: ");
    scanf("%d", &y); // Read second number
    result = invokefunc(operations[index], x, y);
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
int invokefunc(int (*operation)(int, int), int val1, int val2) {
    return operation(val1, val2);
}
