/*2. Refer Job datastructure in Q#1 above. Using uarr, perform below operations.
a. Read and store salary
b. Read and store workerNo
Comment on values of output if salary and workerNo are printed in order. Justify your statement.*/ 


#include <stdio.h>

union Job {
    char name[32];
    unsigned short ucount;
    float salary;
    int workerNo;
    char *orgname;
};

int main() {
    union Job uarr[10]; 
    uarr[0].salary = 50000.0;  
    printf("Salary: %.2f\n", uarr[0].salary); 
    uarr[0].workerNo = 12345; 
    printf("Worker Number: %d\n", uarr[0].workerNo); 
    
    return 0;
}
