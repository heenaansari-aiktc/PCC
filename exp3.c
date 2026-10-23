#include <stdio.h>
int main() {
    int input;
    inputLabel:
        printf("\n Enter a positive integer: ");
        scanf("%d", &input);
    if(input < 0){
         goto inputLabel;
     }
        for(int i=0; i<=input; i++){
            if(i==0){
                continue; 
            }
            printf("\n %d", i);
            if(i%4 == 0 )
            {
                break;
            }
    }
    return 0;
}
