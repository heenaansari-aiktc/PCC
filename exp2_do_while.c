#include <stdio.h>

int main() {

    // =======================================================
    // Looping Statements  do-while
    // =======================================================
    printf("\n=== PART B: LOOPING STATEMENTS ===\n\n");

    // 3. Do-While Loop (Executes at least once)
    printf("\n3. Do-While Loop Example (Secret Password)\n");
    do {
        printf("   Enter the secret 4-digit code (Hint: 1234): ");
        scanf("%d", &password);
        if (password != 1234) {
            printf("   Incorrect code! Try again.\n");
        }
    } while (password != 1234); // Repeats until code is correct
    printf("   -> [Do-While]: Access Granted! Correct password entered.\n");

    return 0;
}