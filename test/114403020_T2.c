#include<stdio.h>

void increase_triangle();

void decimal_binary();

void dectobin(int);

void four_quadrant();

void get_symbol(int,int,int);



int main() {

    int iOption = 0;

    do{
        puts("==== MENU ====");
        puts("1) Option 1 - Increasing Number Triangle Pattern");
        puts("2) Option 2 - Decimal to binary number using recursion");
        puts("3) Option 3 - Printing a Four-Quadrant Pattern");
        puts("(-1) End program");
        printf("%s","Select: ");
        scanf("%d", &iOption);
        
        switch (iOption){

            case 1:{
                increase_triangle();
                break;
            }//end case 1

            case 2:{
                decimal_binary();
                break;
            }//end case 2

            case 3:{
                four_quadrant();
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
    puts("");
    puts("Program ends.");
}

void increase_triangle(){

    /*
    enter size: 5
    1
    2 3
    4 5 6
    7 8 9 10
    11 12 13 14 15
    */

    puts("");

    int iRow, iCol;
    int iNum = 1;
    int iSize = 0;

    printf("Please enter the size of the triangle(1~20): ");
    scanf("%d", &iSize);

    if(iSize < 1 || iSize > 20){
        puts("Invalid input!\n");
        return;
    }//end if
    
    for(iRow=1; iRow<=iSize; iRow++){

        for(iCol=1; iCol<=iRow; iCol++){

            printf("%d ", iNum);
            iNum++;

        }//end for iCol

        puts("");

    }//end for iRow

    puts("");

}//end increase_triangle

void decimal_binary(){

    /*
    10%2=0 10/2=5
    5%2=1 5/2=2
    2%2=0 2/2=1
    1%2=1 1/2=0 
    stop
    */

    puts("");
    puts("Please enter a decimal number: ");
    int iDec = 0;
    scanf("%d", &iDec);

    if(iDec < 0||iDec > 127){
        puts("Invalid input!\n");
        return;
    }//end if

    printf("The binary number is: ");
    dectobin(iDec);
    printf("\n\n");

}//end decimal_binary

void dectobin(int _iN){

    if(_iN == 0){//no binary starting with 0 except for 0 itself
        printf("0");
        return;
    }//end if

    if(_iN == 1){//first bit must be 1 if binary is not 0
        printf("1");
        return;
    }//end if

    int iBit = _iN % 2;
    int iNext = _iN / 2;

    dectobin(iNext);
    printf("%d", iBit);//print after recursive call to reverse the order

}//end dectobin

void four_quadrant(){

    /*
    1<=N<=5

    enter size: 2
    @@|##
    @@|##
    --+---
    %%|&&
    %%|&&
    */
    puts("");
    int iSize = 0;
    printf("Please enter the size of each quadrants(1~5): ");
    scanf("%d", &iSize);
    if(iSize < 1 || iSize > 5){
        puts("Invalid input!\n");
        return;

    }//end if

    puts("");
    int iRow, iCol = 0;

    for(iRow=1; iRow<=iSize*2+1; iRow++){
        for(iCol=1; iCol<=iSize*2+1; iCol++){
            get_symbol(iRow,iCol,iSize);

        }//end for iCol

    }//end for iRow

    puts("");

}//end four_quadrant

void get_symbol(int _iRow,int _iCol,int _iN){

    if(_iRow <= _iN){//upper quadrants
        if(_iCol <= _iN){//left quadrant @
            printf("@");
        }
        else if(_iCol == _iN+1){//middle |
            printf("|");
        }
        else if(_iCol > _iN+1){//right quadrant #
            printf("#");
        }
    }//end upper quadrants

    else if(_iRow == _iN+1){//middle row
        if(_iCol <= _iN){//left -
            printf("-");
        }
        else if(_iCol == _iN+1){//middle +
            printf("+");
        }
        else if(_iCol > _iN+1){//right -
            printf("-");
        }
    }//end middle row

    else if(_iRow > _iN+1){//lower quadrants
        if(_iCol <= _iN){//left quadrant %
            printf("%%");
        }
        else if(_iCol == _iN+1){//middle |
            printf("|");
        }
        else if(_iCol > _iN+1){//right quadrant &
            printf("&");
        }
    }//end lower quadrants

    if(_iCol == _iN*2+1){//end of row
        printf("\n");
    }//end if

}//end get_symbol
