#include <stdio.h>

int main() {
    int num1, num2;
    char opr;

    printf("\n Enter any one arithmetic operator from [ +, -, *, / ] : ");
    scanf(" %c", &opr);

    printf("\n Enter first integer: ");
    scanf("%d", &num1);

    printf("\n Enter second integer: ");
    scanf("%d", &num2);

    switch (opr) {
        case '+':
            printf("\n %d + %d = %d\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("\n %d - %d = %d\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("\n %d * %d = %d\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                printf("\n %d / %d = %d\n", num1, num2, num1 / num2);
            } else {
                printf("\n Error: Division by zero is undefined!\n");
            }
            break;
        default:
            printf("\n Invalid operator! Allowed operators are: +, -, *, /\n");
            break;
    }

    return 0;
}


