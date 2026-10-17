#include <stdio.h>

int main() {
    int n;
    printf("\n Enter a number (N) to print numbers from 1 to N : ");
    scanf("%d", &n);
    printf("\n Output: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
