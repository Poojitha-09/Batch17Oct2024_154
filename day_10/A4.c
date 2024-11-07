/* rotate array every kth element
1 2 3 4 5 6 7 8 9
k= 3
3 2 1 6 5 4 9 8 7 */ 

#include <stdio.h>
int main() {
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);

    for (int i = 0; i < n; i += k) {
        int end = (i + k - 1 < n) ? (i + k - 1) : (n - 1);
        reverseArray(arr, i, end);
    }
    printf("Modified array after rotating every %d-th element:\n", k);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
} 
int reverseArray(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
} 

