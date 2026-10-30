#include <stdio.h>
int main(){
    int arrLength, choice, max, min,i;

    input_label:
    printf("\n Enter the length of the array:");
    scanf("%d", &arrLength);

    if(arrLength <= 0 || arrLength > 100){
        printf("\n Enter a valid length > 0 and  <=100");
        goto input_label;
    }

    int arr[arrLength];
    //take input from the user
    for(i = 0; i<arrLength; i++){
        //printf("\n Enter the elements of the array: ");
        printf("\n Enter the  %d elements of the array: ", i+1);
        scanf("%d", &arr[i]);
    }
    do{
             //MENU
            printf("\n\n Enter one of the option below: ");
            printf("\n\n 1. Display all elements of the array.");
            printf("\n\n 2. Find the maximum and minimum element in the array");
            printf("\n\n 3. Calculate the sum and average of the array elements. ");
            printf("\n\n 4. Search for a given element in the array (linear search).");
            printf("\n\n 5. Reverse the array.");
            printf("\n\n 6. Sort the array in ascending order ");

            printf("\n\n Enter 0 to Exit");
            printf("\n\n Enter your choice: ");
            scanf("%d",&choice);
            switch(choice){
                case 0:
                    printf("\n Exiting the program");
                    break;
                case 1:
                    printf("\n Displaying the elements of array: ");
                        for(i=0; i<arrLength; i++){
                            printf("\t %d", arr[i]);
                        }
                    break;
                case 2:
                    max = arr[0];
                    min = arr[0];
                    for(i = 0; i< arrLength ; i++){
                            if(arr[i]>max){
                                max = arr[i];
                            }
                            if(arr[i]<min){
                                min = arr[i];
                            }
                    }
                    printf("\n Min = %d & Max = %d", min,max);
                default:
                    printf("\n Enter a valid choice.");
            }
        } while(choice != 0);


    return 0;
}
