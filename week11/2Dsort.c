#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void gen2Darr(int _iRow,int _iCol,int _i2Darr[_iRow][_iCol]){//generate 2D array with random number
    srand(time(NULL));
    for(int i=0;i<_iRow;i++){
        for(int j=0;j<_iCol;j++){
            _i2Darr[i][j]=rand()%100;//generate number between 0~99
        }//end for j
    }//end for i
    return;
}//end gen2Darr

void print2Darr(int _iRow,int _iCol,int _i2Darr[_iRow][_iCol]){//print 2D array
    for(int i=0;i<_iRow;i++){
        for(int j=0;j<_iCol;j++){
            printf("%3d",_i2Darr[i][j]);
        }//end for j
        puts("");
    }//end for i
    puts("");
    return;
}//end print2Darr

int sort2Darr1time(int _iSorted,int _iRow,int _iCol,int _i2Darr[_iRow][_iCol]){//sort 2D array one time
    int n=0;//n<=row*col,n=0 means the first number
    int i=0,j=0,k=0,l=0;//i,j for current number,k,l for next number
    int iChanged=0;//flag to check if any number is changed
    for(n=0;n<_iRow*_iCol-_iSorted-1;n++){//-1 because we compare current number with next number
        i=n/_iCol;//get current number row
        j=n%_iCol;//get current number column
        k=(n+1)/_iCol;//get next number row
        l=(n+1)%_iCol;//get next number column
        if(_i2Darr[i][j]>_i2Darr[k][l]){//compare current number with next number
            int iTemp=0;//temporary variable for swapping
            iTemp=_i2Darr[i][j];
            _i2Darr[i][j]=_i2Darr[k][l];
            _i2Darr[k][l]=iTemp;
            iChanged=1;//set flag to 1 if any number is changed
        }//end if
    }//end for n
    _iSorted++;//increase sorted count
    if(iChanged!=1){//if no number is changed, means array is sorted
        _iSorted=-1;
    }
    return _iSorted;
}

void bubble_sort2Darr(int _iRow,int _iCol,int _i2Darr[_iRow][_iCol]){
    int iSorted=0;
    puts("Sorting...\n");
    while(iSorted!=-1){
        iSorted=sort2Darr1time(iSorted,_iRow,_iCol,_i2Darr);
        if(iSorted!=-1){//reduce last print when sorted
            printf("Count: %d\n\n",iSorted);
            print2Darr(_iRow,_iCol,_i2Darr);
        }//end if
    }//end while
    puts("Sorted!!!\n");
    return;
}//end bubble_sort2Darr

void Option1(){//2D array generate and sort
    //generate 2D array
    srand(time(NULL));//seed for random number
    int iRow=rand()%3+2,iCol=rand()%3+2;//row and column between 2~4
    int i2Darr[iRow][iCol];
    printf("\nRow: %d, Col: %d\n\n",iRow,iCol);
    gen2Darr(iRow,iCol,i2Darr);
    //print 2D array
    print2Darr(iRow,iCol,i2Darr);
    //sort 2D array
    bubble_sort2Darr(iRow,iCol,i2Darr);
    //print 2D array
    print2Darr(iRow,iCol,i2Darr);
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