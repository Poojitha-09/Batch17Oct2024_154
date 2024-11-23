/* 2. Accept 3 file names as command line arguments. The first 2 are input files in which first file has to be created as an integer file and the second file has to created as a string file. Merge the contents of these 2 files into the 3rd file. It should be one integer from the first file followed by one line from the second file. */
/*file_operations.h*/  

#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <stdio.h>

// Function declarations
int read_integer(FILE *fp);
int read_string(FILE *fp, char *str, int max_len);
int merge_files(FILE *fp1, FILE *fp2, FILE *fp_out);
void display_file(FILE *fp);

#endif
