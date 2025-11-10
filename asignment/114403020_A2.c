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
    Original number N: 1000
    Reversed number R: 0001

    ==== MENU ====
    1) Option 1 - times table
    2) Option 2 - reverse the number
    (-1) End program

    Please select an option: 2
    Enter a positive integer between 1 and 100000: -5
    Invalid input!

    Enter a positive integer between 1 and 100000: 509
    --- REVERSAL RESULT ---
    Original number N: 509
    Reversed number R: 905

    ==== MENU ====
    1) Option 1 - times table
    2) Option 2 - reverse the number
    (-1) End program

    Please select an option: -1
    Prodram terminated.

    */

void times_table();
int multiplication(int,int);
void reverse_the_number();
int reverse_number(int);

void times_table(){
    puts("");
    int iMul = 0;
    int i,j = 0;
    for(i=1; i<=9; i++){
        for(j=1; j<=9; j++){
            iMul = multiplication(i, j);
            printf("%d*%d=%2d ", i, j, iMul);
        }
        puts("");
    }
    puts("");
}

int multiplication(int _iA, int _iB){
    int iMul = 0;
    iMul = _iA * _iB;
    return iMul;
}

void reverse_the_number(){
    int iN = 0;
    int iR = 0;

    printf("%s","Enter a positive integer between 1 and 100000: ");
    scanf("%d", &iN);

    while(iN < 1 || iN > 100000){
        puts("Invalid input!\n");
        printf("%s","Enter a positive integer between 1 and 100000: ");
        scanf("%d", &iN);
    }

    iR = reverse_number(iN);

    if(iN < 10){
        printf("--- REVERSAL RESULT ---\n");
        printf("Original Number N: %d\n", iN);
        printf("Reversed Number R: %d\n", iR);
    }
    else if(iN < 100){
        printf("--- REVERSAL RESULT ---\n");
        printf("Original Number N: %02d\n", iN);
        printf("Reversed Number R: %02d\n", iR);
    }
    else if(iN < 1000){
        printf("--- REVERSAL RESULT ---\n");
        printf("Original Number N: %03d\n", iN);
        printf("Reversed Number R: %03d\n", iR);

    }
    else if(iN < 10000){
        printf("--- REVERSAL RESULT ---\n");
        printf("Original Number N: %04d\n", iN);
        printf("Reversed Number R: %04d\n", iR);
    }
    else if(iN < 100000){
        printf("--- REVERSAL RESULT ---\n");
        printf("Original Number N: %05d\n", iN);
        printf("Reversed Number R: %05d\n", iR);
    }
    else{
        printf("--- REVERSAL RESULT ---\n");
        printf("Original Number N: %06d\n", iN);
        printf("Reversed Number R: %06d\n", iR);
    }
    puts("");
}

int reverse_number(int _iN){
    int reversed = 0;
    while(_iN != 0){
        int digit = _iN % 10;
        reversed = reversed * 10 + digit;
        _iN /= 10;
    }//end while
    return reversed;
}

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
