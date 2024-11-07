/* DESC : Check whether a given number can be expressed as the sum of two prime number 
    by Naga Poojitha 
    Date : 17,nov 2024 */

#include<stdio.h>
int isPrime(int n);
int main()
{  
    int i ,n; 
    int count=0;
    printf("enter the positive number : "); 
    scanf("%d", &n); 
    for( i= 2; i <= n/2; i++) 
    {
        if(isPrime(i) && isPrime(n-i))
        {
            printf("\n%d = %d + %d\n", n, i ,n-i); 
            count ++;
        }
    } 
    if(count == 0)
        printf("\n NoofWays = %d",-1);  
    else
        printf("\n NoofWays = %d",count); 
    
    return 0;
}
int isPrime(int n) 
{
    int i;
    if(n<=1)
        return 0;
    for(i=2; i * i<= n;i++) 
    {
        if( n%i == 0)
            return 0;
    }
    return 1;
}
