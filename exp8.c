#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "employees.dat"

// Structure to hold employee details
struct Employee {
    int id;
    char name[50];
    char department[30];
    int age;
};

// Function prototypes
void addEmployee();
void updateEmployee();
void displayEmployees();
void clearInputBuffer();

int main() {
    int choice = 0;

    // 1) Ensure the file exists upon startup (creates it if missing)
    FILE *fp = fopen(FILENAME, "ab");/*opens the file specified by FILENAME in binary append mode ("ab")—creating it if it doesn't exist—and stores its stream pointer in fp*/
    //FILE* fopen(*file_name, *access_mode); returns a file pointer to it.
    //ab Opens a file for writing at the end of the file. 
    if (fp == NULL) {
        perror("Error initializing the file");
        return 1;
    }
    fclose(fp); //int fclose(FILE *stream);// is used to safely close an open file stream


    do {
        printf("\n=== Employee Database Menu ===\n");
        printf("1. Add New Employee\n");
        printf("2. Update Existing Employee (by ID)\n");
        printf("3. Display All Employee Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

       scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                updateEmployee();
                break;
            case 3:
                displayEmployees();
                break;
            case 4:
                printf("Exiting program. Data saved to %s.\n", FILENAME);
                break;
            default:
                printf("Invalid choice! Please select 1-4.\n");
        }
    } while (choice != 4);

    return 0;
}

void clearInputBuffer(void) {
    int c;
    while (getchar() != '\n') {
        // Discard leftover characters on the current line
    }
}

// 2) Add a new employee record to the end of the file
void addEmployee(void) {
    FILE *fp = fopen(FILENAME, "ab"); // Open in append-binary mode
    if (fp == NULL) {
        perror("Unable to open file");
        return;
    }

    struct Employee emp;

    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    clearInputBuffer();// to consume leftover characters until a newline or end-of-file is reached.


    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name),stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0';

    printf("Enter Department: ");
    fgets(emp.department, sizeof(emp.department),stdin);
    emp.department[strcspn(emp.department, "\n")] = '\0';

    printf("Enter age: ");
    scanf("%d", &emp.age);
    clearInputBuffer();// to consume leftover characters until a newline or end-of-file is reached.

    if (fwrite(&emp, sizeof(struct Employee), 1, fp) != 1) {
        //size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);  
        perror("Error writing employee record");
        //prints your custom error message followed by a colon
    } else {
        printf("Employee record added successfully!\n");
    }
    /*
    &emp (ptr): The memory address of the data you want to write (emp is a struct Employee variable).

    sizeof(struct Employee) (size): The size in bytes of a single record/item.

    1 (count): How many items of that size you want to write at once (1 employee record).

    fp (stream): The file pointer returned by fopen()*/

    fclose(fp); // Closing flushes data to disk for persistence
}

/**
&emp (ptr): The memory address where the read data will be stored (into the emp struct variable).

sizeof(struct Employee) (size): The byte size of one item/record to read.

1 (count): How many items of that size to read per call (1 employee record at a time).

fp (stream): The open file pointer (FILE *) to read from.

== 1: Checks whether fread() successfully read 1 full record.
 */
// 3) Update an existing employee record in-place by Employee ID
void updateEmployee(void) {
    FILE *fp = fopen(FILENAME, "rb+"); // Open in read/write binary mode R+ read write , b binary
    if (fp == NULL) {
        perror("Unable to open file");
        return;
    }

    int targetId, found = 0;
    struct Employee emp;

    printf("\nEnter Employee ID to update: ");
    scanf("%d", &targetId);
    clearInputBuffer();

    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        //size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
        //== 1: Checks whether fread() successfully read 1 full record.
        if (emp.id == targetId) {
            found = 1;
            printf("Record Found: %s | %s | %d\n", emp.name, emp.department, emp.age);

            printf("Enter New Name: ");
            fgets(emp.name, sizeof(emp.name), stdin);
            emp.name[strcspn(emp.name, "\n")] = '\0';
            

            printf("Enter New Department: ");
            fgets(emp.department, sizeof(emp.department), stdin);
            emp.department[strcspn(emp.department, "\n")] = '\0';
            

            printf("Enter New age: ");
            scanf("%d", &emp.age);
            clearInputBuffer();

            // Move file pointer back by one record size to overwrite it
            if (fseek(fp, -(long)sizeof(struct Employee), SEEK_CUR) != 0) {
                /* int fseek(FILE *stream, long offset, int origin);
                -(long)sizeof(struct Employee) (offset): How many bytes to move.

                sizeof(struct Employee) gives the byte size of one employee struct.

                (long) casts that size to long so it matches fseek's long parameter cleanly.

                - (minus) means move backward from the current position.

                SEEK_CUR - Current file pointer position
*/
                perror("Error seeking in file");
                fclose(fp);
                return;
            }
            /*
            This block moves the file read/write cursor backward by one employee record 
            so the next fwrite() overwrites the record you just read, instead of writing over the next record.*/

            if (fwrite(&emp, sizeof(struct Employee), 1, fp) != 1) {
                perror("Error updating record");
            } else {
                printf("Record updated successfully!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", targetId);
    }

    fclose(fp);
}


// 4) Read and display all employee records from the file
void displayEmployees(void) {
    FILE *fp = fopen(FILENAME, "rb"); // Open in read-binary mode
    if (fp == NULL) {
        perror("Unable to open file");
        return;
    }

    struct Employee emp;
    int count = 0;

    printf("\n%-10s %-25s %-20s %s\n", "ID", "Name", "Department", "Age");
    printf("--------------------------------------------------------------------\n");
    /*/10: Sets the minimum field width to 10 characters. If the text has fewer than 10 characters, printf adds spaces to reach 10. If it already has 10 or more characters, it prints all characters without cutting them off*/

    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        printf("%-10d %-25s %-20s %d\n", emp.id, emp.name, emp.department, emp.age);
        count++;
    }

    if (count == 0) {
        printf("No employee records found.\n");
    }

    fclose(fp);
}
