    #include <stdio.h>    

    // a) Define a structure named Employee
    struct Employee {
        int emp_id;
        char name[50];
        char department[50];
        float salary;
    };

    int main() {
        // Declare a structure variable
        struct Employee emp;
      
        // b) Read and store details of a single employee
        printf("Enter Employee Details:\n");
        printf("Employee ID: ");
        scanf("%d", &emp.emp_id);
        getchar(); // Clear the newline character left by scanf
        printf("First Name: ");
        scanf("%s", &emp.name);
        getchar();
        printf("Department: ");
         scanf("%s", &emp.department);
         getchar();
        //fgets(emp.department, sizeof(emp.department), stdin);
        //emp.department[strcspn(emp.department, "\n")] = '\0'; // Remove trailing newline
        printf("Salary: ");
        scanf("%f", &emp.salary);
      
        // c) Display the stored employee information
        printf("\n\n\n ******* Displaying the details entered by user: ");
        printf("Employee ID : %d\n", emp.emp_id);
        printf("Name        : %s\n", emp.name);
        printf("Department  : %s\n", emp.department);
        printf("Salary      : %.2f\n", emp.salary);
      
        return 0;
    }
