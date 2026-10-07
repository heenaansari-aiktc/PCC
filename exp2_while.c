#include <stdio.h>

int main() {

    int count;

    // =======================================================
    // PART B: Looping Statements while
    // =======================================================
    printf("\n=== PART B: LOOPING STATEMENTS - while ===\n\n");


    // While Loop
    printf("\n Enter a starting number for a countdown using 'while' loop: ");
    scanf("%d", &count);
    printf("   While Loop Countdown: ");
    while (count > 0) {
        printf("%d ", count);
        count--; // Decrement condition
    }
    printf(" Hooray! Countdown finished!!\n");

    return 0;
}