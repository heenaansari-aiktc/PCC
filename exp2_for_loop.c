#include <stdio.h>

int main() {
    int n;

    // =======================================================
    // Looping Statements (for)
    // =======================================================

    //For Loop : Write a C program that asks the user for a number N and uses a for loop to print all numbers from 1 to N
    
    printf("\n Enter a number (N) to print numbers from 1 to N using 'for' loop: ");
    scanf("%d", &n);
    printf("\n For Loop Output: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
        // <--- The update (i++) happens RIGHT HERE, after this line executes
    }
    printf("\n");

    return 0;
}
