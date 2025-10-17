/*
This is your A2 question:
Project Brief: Bulls and Cows Game
Your assigned project is to create a "Bulls and Cows" game. 
You are required to develop a simple program 
that generates a password based on a player's input, 
performs a fixed mathematical operation, 
and outputs the result as a 4-digit password. 
In addition, the player will receive feedback from the program, 
and the format of the feedback is shown below. (50%)

Game Rules Description
1. Accepts Input
The program asks the user to enter a 4-digit number Input 
(range: 1000∼9999).

If the input is not exactly 4 digits, 
the program repeatedly prompts the user to enter a valid number 
until a correct input is provided.

Checking for non-numeric input is optional. 
You will not be penalized for not implementing this feature.

2. Performs Password Calculation
Once a valid number is entered, 
the program calculates the password using the formula:

Password=((Input×3)+1357)(mod10000)
Example Calculations:

Input=123→Password=(123×3+1357)(mod10000)=1736→4-digit 
output 1736

Input=99999→Password=(99999×3+1357)(mod10000)=13954(mod10000)
=3954→4-digit output 3954

However, the password cannot contain duplicate digits. 
For example, Input=1234→Password=(1234×3+1357)(mod10000)=5059, 
which contains two 5's. In this case, 
the program will use 5059 as the new input to generate a new password 
until the password does not contain duplicate digits. 
The flowchart for generating a valid password is given below:
*/

#include<stdio.h>
int main(void){

    unsigned int iGenerate = 0;//no negative iGenerate

    //puts("Enter a 4-digit number to generate a password:");
    //4-digit limit

    puts("Enter a number to generate a password:");
    //no 4-digit limit

    scanf("%u", &iGenerate);
    puts("");//\n
    
    /*
    while(iGenerate < 1000 || iGenerate > 9999){//check 4-digit? (1000~9999)
        puts("Invalid input! Please enter a number between 1000 to 9999.");
        scanf("%d", &iGenerate);
    }//end while iGenerate not 4-digit? (1000~9999)
    */

    int iPassword = (iGenerate % 10000 * 3 + 1357) % 10000;
    int iDigit1 = iPassword / 1000;
    int iDigit2 = (iPassword / 100) % 10;
    int iDigit3 = (iPassword / 10) % 10;
    int iDigit4 = iPassword % 10;

    while(  
        iDigit1 == iDigit2 || //check same digit
        iDigit1 == iDigit3 || //00XX is excluded in this case
        iDigit1 == iDigit4 || 
        iDigit2 == iDigit3 || 
        iDigit2 == iDigit4 || 
        iDigit3 == iDigit4){

        iPassword = (iPassword * 3 + 1357) % 10000;
        iDigit1 = iPassword / 1000;
        iDigit2 = (iPassword / 100) % 10;
        iDigit3 = (iPassword / 10) % 10;
        iDigit4 = iPassword % 10;
        
    }//end while iPassword has same digits

    puts("A secret password has been generated.\n(0XXX is included)\n(123 will be considered as 0123)\n");

    int iRound = 1;
    int iGuess = 0;
    int iGuessDigit1=0, iGuessDigit2=0, iGuessDigit3=0, iGuessDigit4=0;
    int iA=0, iB=0;

    while(iRound <= 10 && iA != 4){

        iA = 0;
        iB = 0;
        printf("--- ROUND %d ---\n", iRound);
        printf("%s","Enter a 4-digit number: ");

        scanf("%d", &iGuess);
        iGuessDigit1 = iGuess / 1000;
        iGuessDigit2 = (iGuess / 100) % 10;
        iGuessDigit3 = (iGuess / 10) % 10;
        iGuessDigit4 = iGuess % 10;

        while(  
            iGuess < 0123 || //check lower limit (include 0000 to 0999)
            iGuess > 9876 || //check upper limit
            iGuessDigit1 == iGuessDigit2 || //check same digit
            iGuessDigit1 == iGuessDigit3 || 
            iGuessDigit1 == iGuessDigit4 ||
            iGuessDigit2 == iGuessDigit3 || 
            iGuessDigit2 == iGuessDigit4 ||
            iGuessDigit3 == iGuessDigit4){

            puts("Invalid input! Please enter a number between 0123 to 9876 without same digit.\n");
            printf("%s","Enter a 4-digit number: ");
            scanf("%d", &iGuess);

            iGuessDigit1 = iGuess / 1000;
            iGuessDigit2 = (iGuess / 100) % 10;
            iGuessDigit3 = (iGuess / 10) % 10;
            iGuessDigit4 = iGuess % 10;

        }//end while iGuess illegal

        if(iGuessDigit1 == iDigit1){
            iA++;
        }
        else if(
            iGuessDigit1 == iDigit2 || 
            iGuessDigit1 == iDigit3 || 
            iGuessDigit1 == iDigit4){
            iB++;
        }
        if(iGuessDigit2 == iDigit2){
            iA++;
        }
        else if(
            iGuessDigit2 == iDigit1 || 
            iGuessDigit2 == iDigit3 || 
            iGuessDigit2 == iDigit4){
            iB++;
        }
        if(iGuessDigit3 == iDigit3){
            iA++;
        }
        else if(
            iGuessDigit3 == iDigit1 || 
            iGuessDigit3 == iDigit2 || 
            iGuessDigit3 == iDigit4){
            iB++;
        }
        if(iGuessDigit4 == iDigit4){
            iA++;
        }
        else if(
            iGuessDigit4 == iDigit1 || 
            iGuessDigit4 == iDigit2 || 
            iGuessDigit4 == iDigit3){
            iB++;
        }
        printf("feedback: %dA%dB\n\n", iA, iB);
        iRound++;

    }//end while iRound

    if(iA == 4){

        puts("GAME ENDS.");
        puts("YOU WIN THE GAME!!");

    }//end if win

    else{

        if(iPassword < 1000){
            printf("The correct password is 0%d.\n\n", iPassword);
        }//<1000 add 0

        else{
        printf("The correct password is %d.\n\n", iPassword);
        }//>=1000

        puts("GAME OVER.");
        puts("YOU LOSE THE GAME.");

    }//end else lose

}//end main