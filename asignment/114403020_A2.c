#include<stdio.h>

    /*

    ==== MENU ====
    1) Option 1 - times table
    2) Option 2 - reverse the number
    (-1) End program

    Please select an option: 5
    Invalid option. Try again.

    Please select an option: 1

    1*1= 1 1*2= 2 ... 1*9= 9
    2*1= 2 2*2= 4 ... 2*9=18
    ...
    9*1= 9 9*2=18 ... 9*9=81

    ==== MENU ====
    1) Option 1 - times table
    2) Option 2 - reverse the number
    (-1) End program

    Please select an option: -1
    Prodram terminated.

    */

    /*
    
    ==== MENU ====
    1) Option 1 - times table
    2) Option 2 - reverse the number
    (-1) End program

    Please select an option: 2
    Enter a positive integer between 1 and 100000: 123456
    Invalid input! 

    Enter a positive integer between 1 and 100000: 1000
    --- REVERSAL RESULT ---
    Original Number N: 1000
    Reversed Number R: 0001

    ==== MENU ====
    1) Option 1 - times table
    2) Option 2 - reverse the number
    (-1) End program

    Please select an option: 2
    Enter a positive integer between 1 and 100000: -5
    Invalid input!

    Enter a positive integer between 1 and 100000: 509
    --- REVERSAL RESULT ---
    Original Number N: 509
    Reversed Number R: 905

    ==== MENU ====
    1) Option 1 - times table
    2) Option 2 - reverse the number
    (-1) End program

    Please select an option: -1
    Prodram terminated.

    */

void times_table();
int multiplication(int,int);
void reverse_the_number();//for text
int reverse_number(int);//for calculation

void times_table(){

    /*
    1*1= 1 1*2= 2 ... 1*9= 9
    2*1= 2 2*2= 4 ... 2*9=18
    ...
    9*1= 9 9*2=18 ... 9*9=81
    */

    puts("");

    int iMul = 0;
    int i,j = 0;

    for(i=1; i<=9; i++){

        for(j=1; j<=9; j++){

            iMul = multiplication(i, j);
            printf("%d*%d=%2d ", i, j, iMul);

        }//end for j

        puts("");

    }//end for i

    puts("");

}//end times_table

int multiplication(int _iA, int _iB){

    int iMul = 0;
    iMul = _iA * _iB;
    return iMul;

}//end multiplication

void reverse_the_number(){//12300 -> 00321

    int iN = 0;
    int iR = 0;

    printf("%s","Enter a positive integer between 1 and 100000: ");
    scanf("%d", &iN);

    while(iN < 1 || iN > 100000){

        puts("Invalid input!\n");
        printf("%s","Enter a positive integer between 1 and 100000: ");
        scanf("%d", &iN);

    }//end while

    iR = reverse_number(iN);//call function to reverse the number

    int iDigitCountN = 0;
    int iTempN = iN;
    while (iTempN != 0){
        iDigitCountN++;
        iTempN /= 10;
    }
    int iDigitCountR = 0;
    int iTempR = iR;
    while (iTempR != 0){
        iDigitCountR++;
        iTempR /= 10;
    }
    int iZeroCount = iDigitCountN - iDigitCountR;

    puts("\n--- REVERSAL RESULT ---");
    printf("Original Number N:");
    printf("%d\n", iN);
    printf("Reversed Number R:");
        for(int i=1; i<=iZeroCount; i++){
        printf("0");
    }
    printf("%d\n", iR);
    puts("");
    
}//end reverse_the_number

int reverse_number(int _iN){//12300 -> 321

    int reversed = 0;

    while(_iN != 0){

        /*
        123456  0
        12345   6
        1234    65
        123     654
        12      6543
        1       65432
        0       654321
        */

        int digit = _iN % 10;
        reversed = reversed * 10 + digit;
        _iN /= 10;

    }//end while

    return reversed;

}//end reverse_number

int main(){

    int iOption = 0;

    do{
        puts("==== MENU ====");
        puts("1) Option 1 - times table");
        puts("2) Option 2 - reverse the number");
        puts("(-1) End program");
        printf("\n%s","Please select an option: ");
        scanf("%d", &iOption);
        
        switch (iOption){

            case 1:{
                times_table();
                break;
            }//end case 1

            case 2:{
                reverse_the_number();
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

}//end main
