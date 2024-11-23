/* 5th question*/

#include <stdio.h>
int main()
{
    float cnt = 1, num = 1000;  // Initialize cnt to 1 to avoid division by zero
    do
    {
        printf("\n%f\n%f", num, cnt);  // Use %f for floating-point numbers
        num /= cnt;  // num is divided by cnt (which is initially 1)
    } while (cnt--); /* Decrements cnt after each iteration */
    return 0;
}

