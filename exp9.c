#include <stdio.h>

// 1. Factorial of a number: n! = n * (n - 1)!
unsigned long long factorial(int n) {
    if (n <= 1) {
        return 1; // Base case
    }
    return n * factorial(n - 1); // Recursive step
}

// 2. Greatest Common Divisor (GCD) using Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a; // Base case
    }
    return gcd(b, a % b); // Recursive step
}

// 3. nth Fibonacci term: fib(n) = fib(n-1) + fib(n-2)
int fibonacci(int n) {
    if (n == 0) return 0; // Base case 1
    if (n == 1) return 1; // Base case 2
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive step
}

// 4. Power calculation: base^exp = base * base^(exp - 1)
long power(int base, int exp) {
    if (exp == 0) {
        return 1; // Base case
    }
    return base * power(base, exp - 1); // Recursive step
}

// 5. Tower of Hanoi
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return; // Base case
    }
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);
    // Move the nth disk from source to destination
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int choice, n, a, b;

    while (1) {
        printf("\n--- Recursion Operations Menu ---\n");
        printf("1. Factorial\n");
        printf("2. GCD (HCF)\n");
        printf("3. Fibonacci Series\n");
        printf("4. Power (x^y)\n");
        printf("5. Tower of Hanoi\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a non-negative integer: ");
                scanf("%d", &n);
                if (n < 0) printf("Factorial is not defined for negative numbers.\n");
                else printf("Factorial of %d = %llu\n", n, factorial(n));
                break;

            case 2:
                printf("Enter two positive integers: ");
                scanf("%d %d", &a, &b);
                printf("GCD of %d and %d = %d\n", a, b, gcd(a, b));
                break;

            case 3:
                printf("Enter number of terms: ");
                scanf("%d", &n);
                printf("Fibonacci Series: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", fibonacci(i));
                }
                printf("\n");
                break;

            case 4:
                printf("Enter base and non-negative exponent: ");
                scanf("%d %d", &a, &b);
                printf("%d^%d = %ld\n", a, b, power(a, b));
                break;

            case 5:
                printf("Enter number of disks: ");
                scanf("%d", &n);
                printf("Steps to solve Tower of Hanoi:\n");
                towerOfHanoi(n, 'A', 'C', 'B');
                break;

            case 6:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
