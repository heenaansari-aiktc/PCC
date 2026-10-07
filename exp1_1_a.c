#include <stdio.h> 
//all your input output functions are in this header file
int main(){
    printf("Hello World!!");

    int input;  //datatype variableName
    printf("\n Enter a character: ");
    input = getchar();
    putchar(input); //to display the input given
    printf("\n");
    return 0;
}
//compile command : gcc exp1_1_a.c -o exp1_1_a
//run command: ./exp1_1_a
