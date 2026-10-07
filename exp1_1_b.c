#include <stdio.h> 
//all your input output functions are in this header file
int main(){
    /** Read two integers using scanf() and display their
    sum, difference, product, and quotient using arithmetic
    operators and printf().
     */
    int num1,num2;
    printf("\n Enter first number:");
    scanf("%d",&num1); //scanf(format Specifier, address of variable)
    printf("\n Enter second number:");
    scanf("%d",&num2);

    printf("\n Sum: %d + %d = %d", num1, num2, num1+num2);
    printf("\n Difference: %d - %d = %d", num1, num2, num1-num2);
    printf("\n Product: %d * %d = %d", num1, num2, num1*num2);
    printf("\n Quotient: %d %% %d = %d", num1, num2, num1%num2);
    return 0;
}
//compile command : gcc exp1_1_b.c -o exp1_1_b
//run command: ./exp1_1_b
