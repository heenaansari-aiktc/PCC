#include <stdio.h>

int main() {
    int num, marks, age, choice, n, count, password;

    // =======================================================
    // PART A: Conditional Statements (If Variants & Switch)
    // =======================================================
    printf("=== PART A: CONDITIONAL STATEMENTS ===\n\n");

    // 1. Simple 'if' 
    printf("1. Enter an integer to check if it's Positive/Negative");
    scanf("%d", &num);
    
    // Simple if variant
    if (num > 0) {
        printf("   -> [Simple if]: The number is positive.\n");
    }
    
    return 0;
}