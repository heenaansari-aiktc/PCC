#include <stdio.h>

int main() {

   
    int choice;
    //  Switch Case with Break
    printf("\n Menu Selection (Switch-Case):\n");
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

    return 0;
}