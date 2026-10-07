#include <stdio.h>

int main() {
    int num;

    // =======================================================
    // PART A: Conditional Statements (If Variants & Switch)
    // =======================================================
    printf("=== PART A: CONDITIONAL STATEMENTS : if ===\n\n");

    // 1. Simple 'if' 
    printf("Enter an integer to check if it's Positive/Negative: ");
    scanf("%d", &num);
    
    // Simple if variant
    if (num > 0) {
        printf("\n The number is positive.\n");
    }
    
    return 0;
}
