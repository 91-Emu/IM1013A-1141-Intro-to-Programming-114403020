#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printarr(int rows, int cols, int arr[rows][cols]){
    printf("\nSorted 2D array (%dx%d):\n\n", rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%3d ", arr[i][j]);
        }//end for
        printf("\n");
    }//end for
}

void arr2Dto1D(int rows, int cols, int source[rows][cols], int dest[]){
    int index = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            dest[index++] = source[i][j];
        }//end for
    }//end for
}

void arr1Dto2D(int rows, int cols, int source[], int dest[rows][cols]){
    int index = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            dest[i][j] = source[index++];
        }//end for
    }//end for
}

void bubble_sort(int arr[], int n){
    int i, j, temp;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                // swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }//end if
        }//end for
    }//end for
}

void Option1(){
    
}//end Option1

void Option2(){
    // Placeholder for Option2 implementation
    puts("Option2 is not yet implemented.\n");
}//end Option2

int main(){

    int iOption = 0;

    do{
        puts("==== MENU ====");
        puts("1) Option 1 - 2D sort");
        puts("2) Option 2 - rotate triangle");
        puts("(-1) End program");
        printf("\n%s","Please select an option: ");
        scanf("%d", &iOption);
        
        switch (iOption){

            case 1:{
                Option1();
                break;
            }//end case 1

            case 2:{
                Option2();
                break;
            }//end case 2
            
            case -1:{
                break;
            }//end case -1

            default:{
                puts("Invalid option. Try again.\n");
                break;
            }//end default

        }//end switch

    }while(iOption != -1);

    puts("Program terminated.");

    return 0;

}//end main