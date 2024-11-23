#include <stdio.h>
#include <stdlib.h>
#include "file_operations.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file1> <input_file2> <output_file>\n", argv[0]);
        return 1;  // Exit if arguments are not correct
    }

    FILE *fp1 = fopen(argv[1], "r");
    if (fp1 == NULL) {
        perror("Error opening first input file");
        return 1;
    }

    FILE *fp2 = fopen(argv[2], "r");
    if (fp2 == NULL) {
        perror("Error opening second input file");
        fclose(fp1);
        return 1;
    }

    FILE *fp_out = fopen(argv[3], "w");
    if (fp_out == NULL) {
        perror("Error opening output file");
        fclose(fp1);
        fclose(fp2);
        return 1;
    }

    // Merge the two files into the output file
    if (merge_files(fp1, fp2, fp_out) != 0) {
        printf("Error merging files\n");
        fclose(fp1);
        fclose(fp2);
        fclose(fp_out);
        return 1;
    }

    printf("Merged file content:\n");
    display_file(fp_out);

    // Close all the files
    fclose(fp1);
    fclose(fp2);
    fclose(fp_out);

    return 0;
}
