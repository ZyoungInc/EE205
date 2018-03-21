#include <stdio.h>
#include <stdlib.h>

/*
 * A badly-written bank account program in C.
 *
 * - Can you pinpoint what makes this program bad?
 * - There is a bug in the program in the "show
 *   transaction" part of the program. Can you
 *   find and fix it?
 */

int main(int argc, char* argv[]) {
    
    fflush(stdout);
    int dn = 0;
    printf("Initial balance,  ");
    fflush(stdout);
    
    struct {
        double b;
        double* pb;
        double d;
        double w;
    } a;
    
    scanf(" %lf", &a.b); 
    char c;
    c=0;
    a.d=0;
    a.w=0;
    
    while (!dn) {
        a.pb = &a.b;
        goto start_again;
        set_dn:
            dn = 0;
        start_again:
        printf("The available actions, :\n"
               "d: Deposit money, \n"
               "w: Withdraw money, \n"
               "g: Get balence, \n"
               "s: Show transations, \n"
               "q: Quit, \n");
        if (dn) break;
        printf("==========");
        printf("==========");
        printf("==========");
        printf("==========");
        printf("\nSelect Action,  ");
        fflush(stdout);
        scanf(" %c", &c);
        if (c == 'd') {
            a.pb = NULL;
            a.pb = &a.b;
            printf("how much money,  ");
            fflush(stdout);
            scanf(" %lf", &a.d); *a.pb = a.b+a.d;
            printf("balance,  ");
            printf("%lf\n", *a.pb);
            printf("deposited money, \n");
            fflush(stdout);
            goto set_dn;
            dn = 0;
        } else if (c == 'w') {
            printf("how much money,  ");
            fflush(stdout);
            scanf(" %lf", &a.w); a.b = a.b-a.w;
            printf("balance,  %lf\n", a.b);
            printf("withdrew money, \n");
            fflush(stdout);
            goto set_dn;
            dn = 0;
        } else if (c == 'g') {
            printf("balance,  ");
            printf("%lf\n", a.b);
            fflush(stdout);
            dn = 1;
            goto set_dn;
            dn = 0;
        } else if (c == 's') {
            printf("last deposit,  %lf\n", a.d);
            printf("last withdrawl,  %lf\n", a.w);
            printf("balance,  %lf\n", a.b);
            printf("showed transactions, \n");
            fflush(stdout);
            dn = 0;
            goto start_again;
        } else if (c == 'q') {
            dn = 1;
        } else {
            printf("INVALID INPUT");
            while ((c = getchar()) != '\n' && c != EOF) { }
            goto set_dn;
        }
    }
    printf("ok bye, \n");
    fflush(stdout);
    return 0;
}

//goto set_dn;
//dn = 0;
