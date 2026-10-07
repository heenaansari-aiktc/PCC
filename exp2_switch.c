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
            printf("\n You ordered a Burger.");
            break; // Exits the switch block
        case 2:
            printf("\n You ordered a Pizza.");
            break;
        case 3:
            printf("\n You ordered Pasta.");
            break;
        default:
            printf("\n Invalid choice entered!");
            break;
    }

    return 0;
}
