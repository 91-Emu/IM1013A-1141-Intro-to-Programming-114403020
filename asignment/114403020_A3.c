/*Opt1
==== MENU ====
1) Option 1 - Split into even and odd number array
2) Option 2 - Calculate Sum of Elements in the Upper Triangle
(-1) End program

Please select an option: 5
Invalid option. Try again.

Please select an option: 1
Enter array size (1-20): 10
Original array:
3 6 10 0 7 5 2 9 4 4

Total even numbers: 6
Even numbers: 6 10 0 2 4 4

Total odd numbers: 4
Odd numbers: 3 7 5 9

==== MENU ====
1) Option 1 - Split into even and odd number array
2) Option 2 - Calculate Sum of Elements in the Upper Triangle
(-1) End program

Please select an option: -1
Program terminated.
*/

/*Opt2
==== MENU ====
1) Option 1 - Split into even and odd number array
2) Option 2 - Calculate Sum of Elements in the Upper Triangle
(-1) End program

Please select an option: 5
Invalid option. Try again.

Please select an option: 2

Enter matrix size N (1-5): 3

Original 2D array (3x3):

12 45 5
22 8 49
15 4 33

Total sum of upper triangle elements: 152

==== MENU ====
1) Option 1 - Split into even and odd number array
2) Option 2 - Calculate Sum of Elements in the Upper Triangle
(-1) End program

Please select an option: -1
Program terminated.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Option1();

void Option2();

void seperate_even_odd(int _iA[], int _iN, int _iEven[], int _iOdd[], int _iCounts[]);

int sum_upper_triangle(int iN, int iMatrix[iN][iN]);



int main(){

    int iOption = 0;

    do{
        puts("==== MENU ====");
        puts("1) Option 1 - Split into even and odd number array");
        puts("2) Option 2 - Calculate Sum of Elements in the Upper Triangle");
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

}//end main

void Option1(){

    printf("\n%s","Enter array size (1-20): ");
    int iN = 0;
    scanf("%d", &iN);

    if(iN < 1 || iN > 20){//check invalid input
        puts("Invalid array size. Return to menu.\n");
        return;
    }//end if

    int iA[iN];
    srand(time(NULL));//seed for random number generation

    for (int i=0; i<iN; i++){
        iA[i] = rand() % 11; // Random number between 0 and 10
    }//end for
    
    printf("Original array:\n");

    for (int i=0; i<iN; i++){//print original array
        printf("%d ", iA[i]);
    }//end for

    printf("\n\n");
    int even[iN];
    int odd[iN];
    int counts[2] = {0, 0}; // counts[0] for even, counts[1] for odd
    seperate_even_odd(iA, iN, even, odd, counts);
    //called seperate_even_odd

    printf("Total even numbers: %d\n", counts[0]);
    printf("Even numbers: ");

    for (int i=0; i < counts[0]; i++) {//print even numbers
        printf("%d ", even[i]);
    }//end for

    printf("\n\n");

    printf("Total odd numbers: %d\n", counts[1]);
    printf("Odd numbers: ");

    for (int i=0; i < counts[1]; i++) {//print odd numbers
        printf("%d ", odd[i]);
    }//end for

    printf("\n\n");

}//end Option1

void Option2(){

    printf("\n%s","Enter matrix size N (1-5): ");
    int iN=0;
    scanf("%d",&iN);

    if(iN < 1 || iN > 5){//check invalid input
        puts("Invalid matrix size. Return to menu.\n");
        return;
    }//end if

    int iMatrix[iN][iN];

    srand(time(NULL));//seed for random number generation

    printf("\nOriginal 2D array (%dx%d):\n\n", iN, iN);

    for(int i=0; i<iN; i++){
        for(int j=0; j<iN; j++){//fill matrix with random numbers
            iMatrix[i][j] = rand() % 51; // Random number between 0 and 50
            printf("%d ", iMatrix[i][j]);//print matrix
        }//end for j
        printf("\n");
    }//end for i
    printf("\n");

    printf("Total sum of upper triangle elements: %d\n\n", sum_upper_triangle(iN, iMatrix));
    //called sum_upper_triangle 

}//end Option2

int sum_upper_triangle(int _iN, int _iMatrix[_iN][_iN]) {

    int sum = 0;

    // Display the matrix and calculate the sum of upper triangle elements
    for (int i = 0; i < _iN; i++) {
        for (int j = 0; j < _iN; j++) {
            if (j >= i) { // Upper triangle sum
                sum += _iMatrix[i][j];
            }//end if

        }//end for j

        printf("\n");

    }//end for i

    printf("\n");
    return sum;

}//end calculate_upper_triangle_sum

void seperate_even_odd(int _iA[], int _iN, int _iEven[], int _iOdd[], int _iCounts[]){

    /*
    integer : Call by Value
    array[] : Call by Reference

    _iCounts[0] : even count
    _iCounts[1] : odd count
    */

    for (int i = 0; i < _iN; i++) {
        if (_iA[i] % 2 == 0) {
            _iEven[_iCounts[0]] = _iA[i];
            _iCounts[0]++;
        }//end if

        else {
            _iOdd[_iCounts[1]] = _iA[i];
            _iCounts[1]++;
        }//end else

    }//end for

}//end split_even_odd