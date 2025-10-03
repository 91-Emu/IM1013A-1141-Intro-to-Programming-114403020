/*
Write a program to simulate a simple ATM system. 
The account starts with an initial balance of **10000**. 
The user can repeatedly enter withdrawal amounts 
until they enter **0** to end the program. (50%)

**Requirements**

1.  Set the balance amount to **10000**, and print out as **"Current balance: 10000"**.
2.  Each time the user enters a withdrawal amount, the program must check:
    * **Exceeding balance**: If the withdrawal amount is greater than the current balance, 
    the system displays **"Insufficient balance"**.
    * Do not deduct the balance.
3.  **Multiple of 100**
    * If the withdrawal amount is not a multiple of 100, the system displays 
    **"Withdrawal amount must be a multiple of 100"**.
4.  **Valid withdrawal**
    * Only if the above conditions are satisfied, deduct the amount and update the balance.
5.  The user may repeat the withdrawal process until entering **0** to quit.
6.  When the process ends, display the **final remaining balance**.
7.  If the user enters an invalid input (e.g., a negative amount), 
    the system displays **"Invalid input, please try again"**.
*/

#include<stdio.h>

int main(void){
    int iBalance = 10000;
    printf("Balance setting: %d\n", iBalance);

    int iWithdraw = 0;
    do{
        printf("Current balance: %d\n\n", iBalance);

        printf("Enter withdrawal amount (0 to quit): ");
        scanf("%d", &iWithdraw);

        if(iWithdraw < 0){
            puts("Invalid input, please try again.");
        }//negative input

        else if(iWithdraw > iBalance){
            puts("Insufficient balance.");
        }//too much

        else if(iWithdraw % 100 != 0 && iWithdraw != 0){
            puts("Withdrawal amount must be a multiple of 100.");
        }//not multiple of 100

        else if(iWithdraw != 0){
            iBalance -= iWithdraw;
            puts("Withdrawal successful!");
        }//Withdrawal successful

    }while (iWithdraw != 0);//end do while

    puts("Transaction ended.");
    printf("Final balance: %d\n", iBalance);
    
}//end main