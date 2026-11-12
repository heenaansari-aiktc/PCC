#include<stdio.h>
void callByValue(int x);
void callByReference(int *x);
int main(){
    int age=19;
    printf("\n Value of age before callByValue function : %d", age);
    callByValue(age);
    printf("\n Value of age after callByValue function : %d", age);

    //CALL BY REFERENCE /CALL BY ADDRESS
    int *ageptr;
    ageptr = &age;

    printf("\n Value of age before callByReference function : %d", age);
    callByReference(ageptr);
    printf("\n Value of age after callByReference function : %d", age);
    return 0;
}

void callByValue(int x){
    x=x*10;
    printf("\n Value of x in callByValue function : %d", x);

}

void callByReference(int *x){
    *x = *x * 10;
    printf("\n Value of x in call by reference function : %d", *x);

}
