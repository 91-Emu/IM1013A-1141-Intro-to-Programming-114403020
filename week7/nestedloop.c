#include<stdio.h>

int main(){
    
    int row=4;
    int column=5;
    int counter=0;
    
    puts("Please enter number of rows:");
    scanf("%d",&row);
    puts("Please enter number of columns:");
    scanf("%d",&column);

    for(int i=1;i<=row;i++){

        for(int j=1;j<=column;j++){

            counter++;
            printf("%2d ",counter);

        }//end for j

        printf("\n");

    }//end for i

}//end main