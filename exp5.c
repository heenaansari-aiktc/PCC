#include<stdio.h>
#include<string.h>
int main(){
    char string1[5],string2[20], string3[20];
    printf("\n Enter first string: ");
    scanf("%s", &string1);

    printf("\n Enter second string: ");
    scanf("%s", &string2);

    printf("\n First string value = %s", string1);
    printf("\n Second string value = %s", string2);

    //to display string length
    printf("\n Length of %s string = %d",string1, strlen(string1));
    printf("\n Length of %s string = %d",string2, strlen(string2));

    //string compare
    int compareOutput = strcmp(string1, string2);
    if(compareOutput == 0){
        printf("\n %s is equal to %s", string1, string2);
    } else{
        printf("\n %s is not equal to %s", string1, string2);
    }

    //Concatenate the second string to the first and display the result
    strcat(string2, string1);
    printf("\n After concatenation value of string 2 = %s", string2);
    
    //copy 2nd string into 3rd string
    strcpy(string3, string2);
    printf("\n Value of third string after copy = %s", string3);
  
    return 0;
}
