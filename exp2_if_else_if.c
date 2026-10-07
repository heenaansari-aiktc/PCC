#include <stdio.h>

int main() {
    int marks;

    // =======================================================
    // PART A: Conditional Statements (If Variants)
    // =======================================================
    printf("=== PART A: CONDITIONAL STATEMENTS -if-else-if ===\n\n");

    

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
    return 0;
}