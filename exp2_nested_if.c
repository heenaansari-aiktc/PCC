#include <stdio.h>

int main() {
    int age;

    // =======================================================
    // PART A: Conditional Statements (If Variants & Switch)
    // =======================================================
    printf("=== PART A: CONDITIONAL STATEMENTS - Nested if===\n\n");



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

    return 0;
}