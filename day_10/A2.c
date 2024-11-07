/* DESC : Program to find nth number made of given four digits 1, 4,6 and 9 as the only digits. 
  Name: Naga Poojitha */ 

#include<stdio.h>  
int find(int k);
int main()
{
    int t; 
    int i;
    int n;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    { 
        for(int i = 0; i<t;i++)
        {
            scanf("%d",&n);
            int result = find(n);
            printf("%d\n",result);
        }
    }
    return 0;
} 
int find(int k)
{ 
    int arr[] = {1,4,6,9};
    int result = 0; 
    int place_value = 1;
    int rem;
    for(;k>0;k/=4)
    { 
        int rem = k%4; 
        result = result + arr[rem]*place_value;
        place_value *= 10; 

    } 
    return result; 
}


  
