#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ip_sym[15], stack[15];
int ip_ptr = 0, st_ptr = 0, len, i;
char temp[2], temp2[2];
char act[15];

void check();

int main() {
    printf("SHIFT REDUCE PARSER\n");
    printf("\nGRAMMER\n");
    printf("\n1)E->E+E\n2)E->E/E\n3)E->E*E\n4)E->a/b\n");
    printf("\nenter the input symbol:\t");
    fgets(ip_sym, sizeof(ip_sym), stdin);
    ip_sym[strcspn(ip_sym, "\n")] = 0;  // Remove newline added by fgets
    
    printf("\n\tstack implementation table");
    printf("\nstack\t\tinput symbol\t\taction");
    printf("\n______\t\t____________\t\t______\n");
    printf("\n$\t\t%s$\t\t\t--", ip_sym);

    strcpy(act, "shift ");
    temp[0] = ip_sym[ip_ptr];
    temp[1] = '\0';
    strcat(act, temp);
    
    len = strlen(ip_sym);

    for (i = 0; i <= len - 1; i++) {
        stack[st_ptr] = ip_sym[ip_ptr];
        stack[st_ptr + 1] = '\0';
        ip_sym[ip_ptr] = ' ';
        ip_ptr++;

        printf("\n$%s\t\t%s$\t\t\t%s", stack, ip_sym, act);

        strcpy(act, "shift ");
        temp[0] = ip_sym[ip_ptr];
        temp[1] = '\0';
        strcat(act, temp);
        
        check();
        st_ptr++;
    }

    st_ptr++;
    check();
    return 0;
}

void check() {
    int flag = 0;
    temp2[0] = stack[st_ptr];
    temp2[1] = '\0';

    if (!strcasecmp(temp2, "a") || !strcasecmp(temp2, "b")) {
        stack[st_ptr] = 'E';
        printf("\n$%s\t\t%s$\t\t\tE->%s", stack, ip_sym, temp2);
        flag = 1;
    }

    if (temp2[0] == '+' || temp2[0] == '*' || temp2[0] == '/') {
        flag = 1;
    }

    if (!strcasecmp(stack, "E+E") || !strcasecmp(stack, "E/E") || !strcasecmp(stack, "E*E")) {
        strcpy(stack, "E");
        st_ptr = 0;

        if (!strcasecmp(stack, "E+E"))
            printf("\n$%s\t\t%s$\t\t\tE->E+E", stack, ip_sym);
        else if (!strcasecmp(stack, "E/E"))
            printf("\n$%s\t\t%s$\t\t\tE->E/E", stack, ip_sym);
        else
            printf("\n$%s\t\t%s$\t\t\tE->E*E", stack, ip_sym);

        flag = 1;
    }

    if (!strcasecmp(stack, "E") && ip_ptr == len) {
        printf("\n$%s\t\t%s$\t\t\tACCEPT", stack, ip_sym);
        exit(0);
    }

    if (flag == 0) {
        printf("\n%s\t\t\t%s\t\t reject", stack, ip_sym);
        exit(0);
    }
}
