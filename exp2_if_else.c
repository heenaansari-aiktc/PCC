#include <stdio.h>

int main() {
    int num;

    // =======================================================
    // PART A: Conditional Statements (If Variants & Switch)
    // =======================================================
    printf("=== PART A: CONDITIONAL STATEMENTS - if-else===\n\n");

    // if-else variant
    if (num % 2 == 0) {
        printf("\n The number %d is Even.", num);
    } else {
        printf("\n The number %d is Odd.", num);
    }

    return 0;
}
