/* 3. Refer the code “find_max.c”. Add a function below to accept variable number of strings and to return the string with maximum length to the caller. In case of strings with same length, return the first string in the input sequence



max_len_string(<variable number of arguments>)


Eg. Code below shoud output “hello”

char *ptr = max_len_string(“hi”, “hello”, “How”, “ Are”, “END”);


printf(“%s”, ptr); */ 


#include <stdio.h>
#include <stdarg.h>
#include <string.h>

char* max_len_string(const char *first, ...) {
    va_list args;
    va_start(args, first);

    const char *max_str = first;
    size_t max_len = strlen(first);
    
    const char *current_str = first;

    // Iterate over the rest of the strings
    while ((current_str = va_arg(args, const char *)) != NULL) {
        size_t current_len = strlen(current_str);
        
        // Compare lengths, if larger, update max_str and max_len
        if (current_len > max_len) {
            max_str = current_str;
            max_len = current_len;
        }
    }

    va_end(args);
    return (char *)max_str;
}

int main() {
    // Test case with variable number of string arguments
    char *ptr = max_len_string("hi", "hello", "How", "Are", "END", NULL);

    printf("%s\n", ptr);  // Expected output: "hello"
    
    return 0;
}
