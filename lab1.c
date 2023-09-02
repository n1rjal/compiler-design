#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Global Variables
char state[3];
bool flag;
int i;


bool dfaEndingWithAb(const char* checkString) {
    strcpy(state, "q0");  // Initial state
    int length = strlen(checkString);

    for (i = 0; i < length; i++) {
        if (checkString[i] == 'a' && strcmp(state, "q0") == 0)
            strcpy(state, "q1");
        else if (checkString[i] == 'b' && strcmp(state, "q0") == 0)
            strcpy(state, "q0");
        else if (checkString[i] == 'a' && strcmp(state, "q1") == 0)
            strcpy(state, "q1");
        else if (checkString[i] == 'b' && strcmp(state, "q1") == 0 && i == (length - 1))
            flag = true;
        else if (checkString[i] == 'b' && strcmp(state, "q1") == 0)
            strcpy(state, "q2");
        else if (checkString[i] == 'a' && strcmp(state, "q2") == 0)
            strcpy(state, "q1");
        else if (checkString[i] == 'b' && strcmp(state, "q2") == 0)
            strcpy(state, "q0");
        else
            flag = false;
    }

    return flag;
}

int main() {
    const char* checkString = "abababbabaabaaab";
    dfaEndingWithAb(checkString);

    printf("\nString: %s\n", checkString);
    printf("Check for ab");
    
    if (flag == true)
        printf("\n\nAccepted\n\n");
    else
        printf("\n\nRejected\n\n");
    
    return 0;
}
