#include <stdio.h>
int main(){
    //a) Read two integer values from the user.
    int num1, num2;
    printf("\n Enter first interger:");
    scanf("%d", &num1);

    printf("\n Enter second interger:");
    scanf("%d", &num2);

    //Demonstrate relational operators (==, !=, <, >, <=,>=) by comparing the two values.
    //0 = False, 1= True"
    //RELATIONAL OPERATORS
    printf("\n Relational operators");
    printf("\n Equal Equals %d == %d : %d", num1,num2,num1==num2);
    printf("\n Not Equals %d != %d : %d", num1,num2, num1!=num2);
    printf("\n Less than %d < %d : %d", num1,num2, num1<num2);
    printf("\n Greater than %d > %d : %d", num1,num2, num1>num2);
    printf("\n Less than Equal to %d <= %d : %d", num1,num2, num1<=num2);
    printf("\n Greater than Equal to %d >= %d : %d", num1,num2, num1>=num2);
    
    //LOGICAL OPERATORS
    printf("\n Logical operators");
    printf("\n (num1>0) && (num2<10) = %d",((num1>0) && (num2<10)));
    printf("\n (num1>0) || (num2<10) = %d",((num1>0) || (num2<10)));
    printf("\n !(num1>num2) = %d",(!(num1>num2)));

    //Bitwise operators

    printf("\n num1 & num2 = %d", num1&num2);
     printf("\n num1 | num2 = %d", num1|num2);
     printf("\n num1 ^ num2 = %d", num1^num2);
     printf("\n ~num1 = %d", ~num1);
     printf("\n num1 left shift by 1 %d", num1 <<1);
     printf("\n num1 right shift by 1 %d", num1 >> 1);
    

    return 0;
}
