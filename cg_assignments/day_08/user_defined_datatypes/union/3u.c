/* 3. Refer Job datastructure in Q#1 above. Assume that myvar is a structure variable. If I need to place 2 bytes (i.e 0x0102) as ucount using a char *ptr then list all possible statements that can be used in _____.*/

#include <stdio.h>

struct Job {
    char name[32];          // 32 bytes
    unsigned short ucount;  // 2 bytes
    float salary;           // 4 bytes
    int workerNo;           // 4 bytes
    char *orgname;          // 8 bytes
};

int main() {
    struct Job myvar;
    char *ptr = (char *)&myvar;  // Pointer to the base address of myvar

    // Assign the value 0x0102 to ucount using ptr
    *(ptr + 32) = 0x01;  // First byte of ucount
    *(ptr + 33) = 0x02;  // Second byte of ucount

    // Print the value of ucount to verify
    printf("ucount: %u\n", myvar.ucount);

    return 0;
}

