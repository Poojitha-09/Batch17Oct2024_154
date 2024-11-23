#include <stdio.h>
int add(int x, int y);
int sub(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);
int (*getaddr(char mychar))(int, int);
int invokefunc(int (*operation)(int, int), int val1);

int main() {
    int x, y, result;
    char operator;
    int (*operation)(int, int); // Function pointer declaration
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator); // The space before %c is to consume any leftover newline character
    operation = getaddr(operator);

    if (operation == NULL) {
        printf("Invalid operator!\n");
        return 1;
    }
    result = invokefunc(operation, 10);
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

int invokefunc(int (*operation)(int, int), int val1) {
    int val2;

    // Read second integer value from user
    printf("Enter second number: ");
    scanf("%d", &val2);

    // Invoke the function passed as the function pointer
    return operation(val1, val2);
}
