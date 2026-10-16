#include <stdio.h>
int main(){
    int arrLength, choice;
    printf("\n Enter the length of the array:");
    scanf("%d", &arrLength);

    if(arrLength <= 0 || arrLength > 100){
        printf("\n Enter a valid length > 0 and  <=100");
        goto input_label;
    }

    int arr[arrLength];
    //take input from the user
    for(int i = 0; i<arrLength; i++){
        //printf("\n Enter the elements of the array: ");
        printf("\n Enter the  %d elements of the array: ", i+1);
        scanf("%d", &arr[i]);
    }
    do{
            printf("\n\n 1. To Display all the elements of array. \n\n Enter 0 to Exit");
            printf("\n\n Enter your choice: ");
            scanf("%d",&choice);
            switch(choice){
                case 0:
                printf("\n Exiting the program");
                    break;
                case 1:
                    printf("\n Displaying the elements of array: ");
                        for(int i=0; i<arrLength; i++){
                            printf("\t %d", arr[i]);
                        }
                    break;
                default:
                    printf("\n Enter a valid choice.");
            }
        } while(choice != 0);


    return 0;
}