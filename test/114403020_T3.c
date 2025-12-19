#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Option1();

void Option2();

void Option3();

void ring_traverse_recursive(int _iN,int iA[_iN][_iN], int _itop, int _ileft, int _ibottom, int _iright);

void flatten_2d_to_1d(int N,int M[][N],int B[]);

void sort_ascending(int n,int B[n]);

void find_max_resource_block(int N,int map[][N]);


int main(){

    int iOption = 0;

    do{
        puts("==== MENU ====");
        puts("1) Option 1 - Ring Traversal of a Square Matrix");
        puts("2) Option 2 - Flatten and Sort");
        puts("2) Option 3 - Maximum Resource Block Finder");
        puts("(-1) End program");
        printf("%s","Select: ");
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
            
            case 3:{
                Option3();
                break;
            }//end case 3

            case -1:{
                break;
            }//end case -1

            default:{
                puts("Invalid option. Try again.\n");
                break;
            }//end default

        }//end switch

    }while(iOption != -1);

    puts("\nProgram ends.");

}//end main

void Option1(){//Ring traversal of a square matrix
    printf("\nPlease enter the size of the matrix (1~5) :");
    int iN=0;
    scanf("%d",&iN);
    if(iN<1||iN>5){//invalid input
        puts("Invalid input!\n");
        return;
    }//end if
    puts("\n[Matrix A]");
    int iA[iN][iN];
    srand(time(NULL));
    for(int i=0;i<iN;i++){
        for(int j=0;j<iN;j++){
            iA[i][j]=rand()%10;
            printf("%d ",iA[i][j]);
        }///end for j
        puts("");
    }//end for i
    puts("\n[Ring traversal output]");
    ring_traverse_recursive(iN,iA,0,0,iN-1,iN-1);
    puts("\n");
    return;
}//end Option1
void ring_traverse_recursive(int _iN, int iA[_iN][_iN], int _itop, int _ileft, int _ibottom, int _iright){
    int iTempSize=_ibottom-_itop+1;
    if(iTempSize==1){//odd size
        printf("%d ",iA[_itop][_ileft]);
        return;
    }
    else if(iTempSize==0){//even size
        return;
    }
    for(int i=0;i<iTempSize;i++){//top row
        printf("%d ",iA[_itop][i]);
    }
    for(int i=1;i<iTempSize;i++){//right column
        printf("%d ",iA[i][_iright]);
    }
    for(int i=iTempSize-2;i>=0;i--){//bottom row
        printf("%d ",iA[_ibottom][i]);
    }
    for(int i=iTempSize-2;i>0;i--){//left column
        printf("%d ",iA[i][_ileft]);
    }
    ring_traverse_recursive(_iN, iA, _itop+1, _ileft+1, _ibottom-1, _iright-1);//shrink box
    return;
}//end ring_traverse_recursive

void Option2(){//Flatten and sort
    printf("\nPlease enter the size of the matrix (1~5) :");
    int iN=0;
    scanf("%d",&iN);
    if(iN<1||iN>5){//invalid input
        puts("Invalid input!\n");
        return;
    }//end if
    printf("\n[Matrix M (%d x %d)]\n",iN,iN);
    int iM[iN][iN];
    srand(time(NULL));
    for(int i=0;i<iN;i++){
        for(int j=0;j<iN;j++){
            iM[i][j]=rand()%100;
            printf("%2d ",iM[i][j]);
        }
        puts("");
    }//end for i
    puts("");
    int B[iN*iN];
    puts("[Flattened 1D array B in row-major order]");
    flatten_2d_to_1d(iN,iM,B);
    puts("[Sorted 1D array B (ascending)]");
    sort_ascending(iN,B);
    return;
}//end Option2
void flatten_2d_to_1d(int _iN,int _iM[_iN][_iN],int _B[_iN]){
    int iBn;//index for B
    for(int i=0;i<_iN;i++){
        for(int j=0;j<_iN;j++){
            iBn=i*_iN+j;
            _B[iBn]=_iM[i][j];
            printf("%2d ",_B[iBn]);
        }//end for j
    }//end for i
    puts("\n");
    return;
}//end flatten_2d_to_1d
void sort_ascending(int n,int B[n*n]){//bubble sort
    int iTemp;
    for(int j=0;j<n*n;j++){//sort n times
        for(int i=0;i<n*n-1;i++){//sort 1 time
            if(B[i]>B[i+1]){
                iTemp=B[i];
                B[i]=B[i+1];
                B[i+1]=iTemp;
            }//end if
        }//end for i
    }//end for j
    for(int i=0;i<n*n;i++){//print B
        printf("%2d ",B[i]);
    }//end for i
    puts("\n");
    return;
}//end sort_ascending

void Option3(){//Maximum resource block finder
    printf("\nPlease enter the size of the matrix (3~10) :");
    int iN=0;
    scanf("%d",&iN);
    if(iN<3||iN>10){//invalid input
        puts("Invalid input!\n");
        return;
    }//end if
    printf("\nMatrix M (%d x %d)\n",iN,iN);
    int map[iN][iN];
    srand(time(NULL));
    for(int i=0;i<iN;i++){
        for(int j=0;j<iN;j++){
            map[i][j]=rand()%10;
            printf("%d ",map[i][j]);
        }//end for j
        puts("");
    }//end for i
    puts("");
    find_max_resource_block(iN,map);

    return;
}//end Option3
void find_max_resource_block(int _iN,int map[][_iN]){//find 3x3 max resource block
    int iBestSum=0;
    int iSum=0;
    int iBestRow,iBestCol;
    for(int i=0;i<_iN-2;i++){
        for(int j=0;j<_iN-2;j++){
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    iSum+=map[k+i][l+j];
                }
            }
            if(iSum>iBestSum){
                iBestSum=iSum;
                iBestRow=i;
                iBestCol=j;
            }
            iSum=0;
        }//end for j
    }//end for i
    
    printf("Maximum resource sum: %d",iBestSum);
    printf("\nTop-left coordinate: (%d, %d)",iBestCol,iBestRow);
    puts("\nMax resource block:");
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",map[i+iBestRow][j+iBestCol]);
        }//end for j
        puts("");
    }//end for i
    puts("");
    return;
}//end find_max_resource_block
