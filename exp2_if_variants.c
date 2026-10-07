#include <stdio.h>

int main() {
    int num, marks, age, choice, n, count, password;

    // =======================================================
    // PART A: Conditional Statements (If Variants & Switch)
    // =======================================================
    printf("=== PART A: CONDITIONAL STATEMENTS ===\n\n");

    // 1. Simple 'if' and 'if-else'
    printf("1. Enter an integer to check if it's Positive/Negative & Even/Odd: ");
    scanf("%d", &num);
    
    // Simple if variant
    if (num > 0) {
        printf("   -> [Simple if]: The number is positive.\n");
    }

    // if-else variant
    if (num % 2 == 0) {
        printf("   -> [if-else]: The number %d is Even.\n", num);
    } else {
        printf("   -> [if-else]: The number %d is Odd.\n", num);
    }

    // 2. if-else-if Ladder
    printf("\n2. Enter your marks (0-100) for grading: ");
    scanf("%d", &marks);

    if (marks >= 90) {
        printf("   -> [if-else-if]: Grade A+ (Outstanding)\n");
    } else if (marks >= 75) {
        printf("   -> [if-else-if]: Grade A (Very Good)\n");
    } else if (marks >= 60) {
        printf("   -> [if-else-if]: Grade B (Good)\n");
    } else if (marks >= 40) {
        printf("   -> [if-else-if]: Grade C (Pass)\n");
    } else {
        printf("   -> [if-else-if]: Grade F (Fail)\n");
    }

    // 3. Nested 'if'
    printf("\n3. Enter your age for voting eligibility: ");
    scanf("%d", &age);

    if (age >= 18) {
        // Inner (nested) if
        printf("   -> Age >= 18. Do you have a Voter ID? (Enter 1 for Yes, 0 for No): ");
        int hasID;
        scanf("%d", &hasID);

        if (hasID == 1) {
            printf("   -> [Nested if]: You are eligible to vote!\n");
        } else {
            printf("   -> [Nested if]: You are an adult, but need a Voter ID to vote.\n");
        }
    } else {
        printf("   -> [Nested if]: You are a minor and not eligible to vote.\n");
    }

    // 4. Switch Case with Break
    printf("\n4. Menu Selection (Switch-Case):\n");
    printf("   1. Burger\n   2. Pizza\n   3. Pasta\n");
    printf("   Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("   -> [Switch]: You ordered a Burger. (Break executed)\n");
            break; // Exits the switch block
        case 2:
            printf("   -> [Switch]: You ordered a Pizza. (Break executed)\n");
            break;
        case 3:
            printf("   -> [Switch]: You ordered Pasta. (Break executed)\n");
            break;
        default:
            printf("   -> [Switch]: Invalid choice entered!\n");
            break;
    }

    // =======================================================
    // PART B: Looping Statements (for, while, do-while)
    // =======================================================
    printf("\n=== PART B: LOOPING STATEMENTS ===\n\n");

    // 1. For Loop
    printf("1. Enter a number (N) to print numbers from 1 to N using 'for' loop: ");
    scanf("%d", &n);
    printf("   For Loop Output: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
        // <--- The update (i++) happens RIGHT HERE, after this line executes
    }
    printf("\n");

    // 2. While Loop
    printf("\n2. Enter a starting number for a countdown using 'while' loop: ");
    scanf("%d", &count);
    printf("   While Loop Countdown: ");
    while (count > 0) {
        printf("%d ", count);
        count--; // Decrement condition
    }
    printf(" Hooray! Countdown finished!!\n");

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