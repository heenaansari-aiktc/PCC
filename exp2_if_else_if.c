#include <stdio.h>

int main() {
    int marks;

    // =======================================================
    // PART A: Conditional Statements (If Variants)
    // =======================================================
    printf("=== PART A: CONDITIONAL STATEMENTS -if-else-if ===\n\n");

    

    // 2. if-else-if Ladder
    printf("\n Enter your marks (0-100) for grading: ");
    scanf("%d", &marks);

    if (marks >= 90) {
        printf("\n Grade A+ (Outstanding)");
    } else if (marks >= 75) {
        printf("\n Grade A (Very Good)");
    } else if (marks >= 60) {
        printf("\n Grade B (Good)");
    } else if (marks >= 40) {
        printf("\n Grade C (Pass)");
    } else {
        printf("\n Grade F (Fail)\n");
    }
    return 0;
}
