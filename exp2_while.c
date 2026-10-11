#include <stdio.h>

int main() {

    int count;

    // =======================================================
    // PART B: Looping Statements while
    // Write a C program that asks the user for a starting number 
    // and uses a while loop to print a countdown down to 1, ending with the message "Hooray! Countdown finished!!"
    // =======================================================
    
    // While Loop
    printf("\n Enter a starting number for a countdown using 'while' loop: ");
    scanf("%d", &count);
    printf("\n While Loop Countdown: ");
    while (count > 0) {
        printf("%d ", count);
        count--; // Decrement condition
    }
    printf("\n Hooray! Countdown finished!!\n");

    return 0;
}
