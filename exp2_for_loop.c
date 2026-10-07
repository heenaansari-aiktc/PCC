#include <stdio.h>

int main() {
    int n;

    // =======================================================
    // Looping Statements (for)
    // =======================================================
    printf("\n=== PART B: LOOPING STATEMENTS - FOR loop ===\n\n");

    // 1. For Loop
    printf("1. Enter a number (N) to print numbers from 1 to N using 'for' loop: ");
    scanf("%d", &n);
    printf("   For Loop Output: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
        // <--- The update (i++) happens RIGHT HERE, after this line executes
    }
    printf("\n");

    return 0;
}