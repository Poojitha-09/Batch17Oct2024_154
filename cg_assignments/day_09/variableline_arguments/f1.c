/* Implement a log() with signature as below to display all the input arguments as per their type. [Hint: In log() , use vfprintf() to display the received inputs] */ 


#include <stdio.h>
#include <stdarg.h>

void log(const char *format, ...) {
    va_list args;
    va_start(args, format);  // Initialize va_list with format
    
    // vfprintf prints the formatted string using the format and args
    vfprintf(stdout, format, args);
    
    va_end(args);  // Clean up the va_list
}

int main() {
    int count = 10;
    char prefix = 'h';
    char label[] = "India";

    // Example usage of the log function
    log("count:%d, prefix:%c, label:%s\n", count, prefix, label);

    return 0;
}
