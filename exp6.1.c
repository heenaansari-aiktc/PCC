#include <stdio.h>
//declaration:
void displayArray(int arr[], int lengthArray);
void calulateMinMax(int arr[], int lengthArray);
void calculateSumAvg(int arr[], int lengthArray){
         //CACULATE THE SUM AND AVERAGE
                    int sum=0;
                    for(int i=0 ; i< lengthArray; i++){
                        sum = sum + arr[i];
                    }
                    int avg = sum / lengthArray;
                    printf("\n Sum = %d and Average = %d", sum, avg);
}
int linearSearch(int arr[], int lengthArray);
void arrayReverse(int arr[], int lengthArray);

int main(){
    int arrLength, choice,i,keyIndex;


    input_label:
    printf("\n Enter the length of the array:");
    scanf("%d", &arrLength);

    if(arrLength <= 0 || arrLength > 100){
        printf("\n Enter a valid length > 0 and  <=100");
        goto input_label;
    }

    int arr[arrLength];
    //take input from the user
    for(i = 0; i <= arrLength-1; i++){
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
                    displayArray(arr, arrLength);
                    break;
                case 2:
                    calulateMinMax(arr, arrLength);
                    break;
                case 3:
                   calculateSumAvg(arr, arrLength);
                    break;
                case 4:
                    keyIndex = linearSearch(arr, arrLength);
                    if(keyIndex == -1){
                        printf("\n Element is not present in array");
                    } else {
                        printf("\n %Element is at index %d", keyIndex);
                    }
                    break;
                case 5:
                    printf("\n in case 5");
                   
                    break;
                default:
                    printf("\n Enter a valid choice.");
            }
        } while(choice != 0);


    return 0;
}

void displayArray(int arr[], int lengthArray){
    for(int i=0 ; i<= lengthArray-1; i++){
        printf("%d ", arr[i]);
    }
} 

void calulateMinMax(int arr[], int lengthArray){
    int max,min;
                    max = arr[0];
                    min = arr[0];
                    for(int i = 0; i< lengthArray ; i++){
                            if(arr[i]>max){
                                max = arr[i];
                            }
                            if(arr[i]<min){
                                min = arr[i];
                            }
                    }
                    printf("\n Min = %d & Max = %d", min,max);
}



int linearSearch(int arr[], int lengthArray){
    //HW- linear search - first occurence
                    int keyIndex = -1, key;
                    printf("\n Enter the key value to be searched: ");
                    scanf("%d", &key);

                    for(int i=0; i <= lengthArray-1 ; i++){
                        if(arr[i] == key){
                            keyIndex =  i;
                            break;
                        }
                    }//for loop ends
                    return keyIndex;

}

void arrayReverse(int arr[], int lengthArray){
     //REVERSE AN ARRAY
                    int start = 0; //start index of array
                    int end = lengthArray - 1; // intialize with last index of array
                    int temp;
            
                    while(start < end){
                        temp = arr[start];
                        arr[start] = arr[end];
                        arr[end] = temp;
                        start++;
                        end--;
                    }

                    printf("\n Displaying the reverse of array: ");
                    displayArray(arr, lengthArray);
}
