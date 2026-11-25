#include <stdio.h>
#include <string.h>

#define FILE_NAME "employees.dat"

// 1. Structure definition for an Employee
struct Employee {
    int id;
    char name[50];
    char department[30];
    float salary;
};

// Function prototypes using pointers to struct Employee
void addEmployee(struct Employee *emp);
void displayEmployees(struct Employee *emp);
void searchEmployee(struct Employee *emp, int searchId);

int main() {
    struct Employee emp; // Stack variable; its address (&emp) is passed via pointer
    int choice;
    int searchId;

    do {
        printf("\n=== Employee Management System ===\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(&emp);
                break;
            case 2:
                displayEmployees(&emp);
                break;
            case 3:
                printf("Enter Employee ID to search: ");
                scanf("%d", &searchId);
                searchEmployee(&emp, searchId);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter 1 to 4.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a new employee record to the binary file
void addEmployee(struct Employee *emp) {
    FILE *fp = fopen(FILE_NAME, "ab"); // "ab" = append binary (creates file if absent)
    if (fp == NULL) {
        printf("Error: Could not open file '%s' for writing.\n", FILE_NAME);
        return;
    }

    printf("\n--- Add New Employee ---\n");
    printf("Enter ID: ");
    scanf("%d", &emp->id);

    printf("Enter Name: ");
    scanf(" %49[^\n]", emp->name); // Reads full name including spaces

    printf("Enter Department: ");
    scanf(" %29[^\n]", emp->department);

    printf("Enter Salary: ");
    scanf("%f", &emp->salary);

    // Write 1 Employee structure from the pointer address into the file
    if (fwrite(emp, sizeof(struct Employee), 1, fp) == 1) {
        printf("Employee record saved successfully!\n");
    } else {
        printf("Error: Failed to write record to file.\n");
    }

    fclose(fp);
}

// Function to display all employee records from the file
void displayEmployees(struct Employee *emp) {
    FILE *fp = fopen(FILE_NAME, "rb"); // "rb" = read binary
    if (fp == NULL) {
        printf("No employee records found yet (file does not exist).\n");
        return;
    }

    int count = 0;
    printf("\n--- All Employee Records ---\n");
    printf("%-10s %-25s %-20s %-12s\n", "ID", "Name", "Department", "Salary");
    printf("---------------------------------------------------------------------\n");

    while (fread(emp, sizeof(struct Employee), 1, fp) == 1) {
        printf("%-10d %-25s %-20s %-12.2f\n",
               emp->id, emp->name, emp->department, emp->salary);
        count++;
    }

    if (count == 0) {
        printf("File is empty. No records to display.\n");
    }

    fclose(fp);
}

// Function to search for an employee record by ID
void searchEmployee(struct Employee *emp, int searchId) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("No employee records found (file does not exist).\n");
        return;
    }

    int found = 0;
    while (fread(emp, sizeof(struct Employee), 1, fp) == 1) {
        if (emp->id == searchId) {
            printf("\n--- Employee Found ---\n");
            printf("ID         : %d\n", emp->id);
            printf("Name       : %s\n", emp->name);
            printf("Department : %s\n", emp->department);
            printf("Salary     : %.2f\n", emp->salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", searchId);
    }

    fclose(fp);
}
