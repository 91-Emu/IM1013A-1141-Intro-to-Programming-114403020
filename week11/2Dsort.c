#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void gen2Darr(int _iRow,int _iCol,int _i2Darr[_iRow][_iCol]){
    srand(time(NULL));
    for(int i=0;i<_iRow;i++){
        for(int j=0;j<_iCol;j++){
            _i2Darr[i][j]=rand()%100;
        }
    }
    return;
}

void print2Darr(int _iRow,int _iCol,int _i2Darr[_iRow][_iCol]){
    for(int i=0;i<_iRow;i++){
        for(int j=0;j<_iCol;j++){
            printf("%3d",_i2Darr[i][j]);
        }
    puts("");
    }
    return;
}

int sort2Darr1time(int _iSorted,int _iRow,int _iCol,int _i2Darr[_iRow][_iCol]){
    int n=0;//n<=row*col,n=0 means the first number
    int i=0,j=0,k=0,l=0;
    int iChanged=0;
    for(n=0;n<_iRow*_iCol-_iSorted;n++){
        i=n/_iCol;
        j=n%_iCol;
        k=(n+1)/_iCol;
        l=(n+1)%_iCol;
        if(_i2Darr[i][j]>_i2Darr[k][l]){
            int iTemp=0;
            iTemp=_i2Darr[i][j];
            _i2Darr[i][j]=_i2Darr[k][l];
            _i2Darr[k][l]=iTemp;
            iChanged=1;
        }
    }
    _iSorted++;
    if(iChanged!=1){
        _iSorted=-1;
    }
    return _iSorted;
}

void bubble_sort2Darr(int _iRow,int _iCol,int _i2Darr[_iRow][_iCol]){
    int iSorted=0;
    puts("Sorting...\n");
    while(iSorted!=-1){
        print2Darr(_iRow,_iCol,_i2Darr);
        iSorted=sort2Darr1time(iSorted,_iRow,_iCol,_i2Darr);
    }
    puts("Sorted!!!\n");
    return;
}

void Option1(){//2D array generate and sort
    //generate 2D array
    srand(time(NULL));
    int iRow=rand()%3+2,iCol=rand()%3+2;
    int i2Darr[iRow][iCol];
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