/*
Read a string (full name) using gets() and display it
using puts(). */
#include <stdio.h>
int main(){
    puts("Enter your full name");
    char fullName[50];//declaring array of size 50
    //gets is deprecated
    fgets(fullName, sizeof(fullName),stdin);
    puts("Name entered by you is:");
    puts(fullName);
    return 0;
}

//compile command : gcc exp1_1_c.c -o exp1_1_c
//run command: ./exp1_1_c