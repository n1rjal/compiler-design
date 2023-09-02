#include <stdio.h>
#include <string.h>

char op[2], arg1[5], arg2[5], result[5];

int main() {
    FILE *fp1, *fp2;

    // Open the input and output files
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");

    // Check if the input file is successfully opened
    if(!fp1) {
        perror("Failed to open input.txt");
        return 1;
    }

    // Check if the output file is successfully opened
    if(!fp2) {
        perror("Failed to open output.txt");
        return 1;
    }

    // Read from the input file until end of file
    while (!feof(fp1)) {
        fscanf(fp1, "%s%s%s%s", op, arg1, arg2, result);

        // Handle addition operation
        if (strcmp(op, "+") == 0) {
            fprintf(fp2, "\n MOV R0,%s", arg1);
            fprintf(fp2, "\n ADD R0,%s", arg2);
            fprintf(fp2, "\n MOV %s,R0", result);
        }

        // Handle multiplication operation
        else if (strcmp(op, "*") == 0) {
            fprintf(fp2, "\n MOV R0,%s", arg1);
            fprintf(fp2, "\n MUL R0,%s", arg2);
            fprintf(fp2, "\n MOV %s,R0", result);
        }

        // Handle subtraction operation
        else if (strcmp(op, "-") == 0) {
            fprintf(fp2, "\n MOV R0,%s", arg1);
            fprintf(fp2, "\n SUB R0,%s", arg2);
            fprintf(fp2, "\n MOV %s,R0", result);
        }

        // Handle division operation
        else if (strcmp(op, "/") == 0) {
            fprintf(fp2, "\n MOV R0,%s", arg1);
            fprintf(fp2, "\n DIV R0,%s", arg2);
            fprintf(fp2, "\n MOV %s,R0", result);
        }

        // Handle assignment operation
        else if (strcmp(op, "=") == 0) {
            fprintf(fp2, "\n MOV R0,%s", arg1);
            fprintf(fp2, "\n MOV %s,R0", result);
        }
    }

    // Close the input and output files
    fclose(fp1);
    fclose(fp2);

    return 0;
}
