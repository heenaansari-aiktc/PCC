#include<stdio.h>
int main(){
    int *ptr;
    int a = 10;

    ptr = &a;
    printf("\n Value of a : %d", a);
    printf("\n Value/ address in ptr variable: %d", ptr);
    printf("\n Value of the variable pointed by ptr = %d", *ptr);

    a = a+10;
    printf("\n Value of a : %d", a);
    printf("\n Value/ address in ptr variable: %d", ptr);
    printf("\n Value of the variable pointed by ptr = %d", *ptr);
    return 0;
}
