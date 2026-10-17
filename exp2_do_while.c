#include <stdio.h>
int main() {
    int password;
    /** =======================================================
    // Looping Statements  do-while - implement Secret Password
     =======================================================**/
   //Do-While Loop (Executes at least once)
    printf("\n Do-While Loop Example (Secret Password) \n");
    do {
        printf("\n Enter the secret 4-digit code (Hint: 1234): ");
        scanf("%d", &password);
        if (password != 1234) {
            printf("\n Incorrect code! Try again.\n");
        }
    } while (password != 1234); // Repeats until code is correct
    printf("\n Access Granted! Correct password entered.\n");
    return 0;
}
