/* Write a program to find the  n-th number made of prime digits *\
  
#include <stdio.h>
#define MAX_NUM 10000
int generate_prime_digit_numbers(int limit, int prime_numbers[]);
int main() {
    int T;
    int prime_numbers[MAX_NUM];
    generate_prime_digit_numbers(MAX_NUM, prime_numbers);
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int N;
        scanf("%d", &N);
        printf("%d\n", prime_numbers[N - 1]);
    }

    return 0;
}
int is_prime_digit_number(int num) {
    int valid_digits[] = {2, 3, 5, 7};
    int is_valid;
    
    while (num > 0) {
        int digit = num % 10;
        is_valid = 0; 
        for (int i = 0; i < 4; i++) {
            if (digit == valid_digits[i]) {
                is_valid = 1;
                break;
            }
        }

        if (!is_valid) {
            return 0; 
        }
        
        num /= 10; 
    }
    return 1; 
}
int generate_prime_digit_numbers(int limit, int prime_numbers[]) {
    int num = 2;  
    int count = 0;

    while (count < limit) {
        if (is_prime_digit_number(num)) {
            prime_numbers[count] = num;
            count++;
        }
        num++;
    }
} 
