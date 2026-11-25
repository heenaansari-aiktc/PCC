#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.dat"
#define NAME_LEN 100
#define DEPT_LEN 50

/* 1. Structure to define an Employee */
struct Employee {
    int id;
    char name[NAME_LEN];
    char department[DEPT_LEN];
    float salary;
};

/* Function prototypes */
void clearInputBuffer(void);
void addEmployee(const char *filename);
void displayEmployees(const char *filename);
void searchEmployeeById(const char *filename, int targetId);
void printEmployee(const struct Employee *emp);

int main(void) {
    int choice;
    int searchId;

    do {
        printf("\n=== Employee Management System ===\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                addEmployee(FILE_NAME);
                break;
            case 2:
                displayEmployees(FILE_NAME);
                break;
            case 3:
                printf("Enter Employee ID to search: ");
                if (scanf("%d", &searchId) != 1) {
                    printf("Invalid ID input.\n");
                    clearInputBuffer();
                } else {
                    clearInputBuffer();
                    searchEmployeeById(FILE_NAME, searchId);
                }
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select 1 to 4.\n");
        }
    } while (choice != 4);

    return 0;
}

/* Clears leftover characters (such as '\n') from stdin */
void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* discard */
    }
}

/* 2. Function to add a new employee record using dynamic memory & file handling */
void addEmployee(const char *filename) {
    /* Dynamically allocate memory for one Employee using a pointer */
    struct Employee *newEmp = (struct Employee *)malloc(sizeof(struct Employee));
    if (newEmp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\n--- Add New Employee ---\n");
    printf("Enter ID: ");
    while (scanf("%d", &newEmp->id) != 1) {
        printf("Invalid ID. Enter an integer: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    printf("Enter Name: ");
    if (fgets(newEmp->name, NAME_LEN, stdin) != NULL) {
        newEmp->name[strcspn(newEmp->name, "\n")] = '\0'; /* remove trailing newline */
    }

    printf("Enter Department: ");
    if (fgets(newEmp->department, DEPT_LEN, stdin) != NULL) {
        newEmp->department[strcspn(newEmp->department, "\n")] = '\0';
    }

    printf("Enter Salary: ");
    while (scanf("%f", &newEmp->salary) != 1 || newEmp->salary < 0) {
        printf("Invalid salary. Enter a non-negative number: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    /* Open file in append-binary mode so existing records are preserved */
    FILE *fp = fopen(filename, "ab");
    if (fp == NULL) {
        printf("Error opening file '%s' for writing.\n", filename);
        free(newEmp);
        return;
    }

    size_t written = fwrite(newEmp, sizeof(struct Employee), 1, fp);
    if (written == 1) {
        printf("Employee record saved successfully!\n");
    } else {
        printf("Failed to write employee record to file.\n");
    }

    fclose(fp);
    free(newEmp); /* Free dynamically allocated memory */
}

/* 3. Function to display all employee records from the file */
void displayEmployees(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("No records found yet (file '%s' does not exist).\n", filename);
        return;
    }

    struct Employee *tempEmp = (struct Employee *)malloc(sizeof(struct Employee));
    if (tempEmp == NULL) {
        printf("Memory allocation failed!\n");
        fclose(fp);
        return;
    }

    int count = 0;
    printf("\n--- Employee Records ---\n");
    while (fread(tempEmp, sizeof(struct Employee), 1, fp) == 1) {
        count++;
        printf("\nRecord #%d\n", count);
        printEmployee(tempEmp);
    }

    if (count == 0) {
        printf("No employee records available.\n");
    }

    free(tempEmp);
    fclose(fp);
}

/* 4. Function to search for an employee by ID using a pointer */
void searchEmployeeById(const char *filename, int targetId) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("No records found (file '%s' does not exist).\n", filename);
        return;
    }

    struct Employee *currentEmp = (struct Employee *)malloc(sizeof(struct Employee));
    if (currentEmp == NULL) {
        printf("Memory allocation failed!\n");
        fclose(fp);
        return;
    }

    int found = 0;
    while (fread(currentEmp, sizeof(struct Employee), 1, fp) == 1) {
        if (currentEmp->id == targetId) {
            printf("\n--- Employee Found ---\n");
            printEmployee(currentEmp);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", targetId);
    }

    free(currentEmp);
    fclose(fp);
}

/* Helper function using a const pointer to print employee details */
void printEmployee(const struct Employee *emp) {
    printf("  ID         : %d\n", emp->id);
    printf("  Name       : %s\n", emp->name);
    printf("  Department : %s\n", emp->department);
    printf("  Salary     : %.2f\n", emp->salary);
}
