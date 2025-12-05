#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void initializeArray(int _iSize, int array[_iSize]);
void printArray(int _iSize, int array[_iSize]) ;
void randomizeArray(int _iSize, int array[_iSize]);
void uninitializeArray(int _iSize, int array[_iSize]);

int main(void) {

    int iSize;
    printf("Enter size of array:");
    scanf("%d", &iSize);

    int iArray[iSize];

    uninitializeArray(iSize, iArray);
    initializeArray(iSize, iArray);
    randomizeArray(iSize, iArray);

}// end main

void initializeArray(int _iSize, int _iArray[_iSize]) {//{1,1,1,1,1}
    for (int i = 0; i < _iSize; i++) {
        _iArray[i] = 1;
    }
    printArray(_iSize, _iArray);

}// end initializeArray

void printArray(int _iSize, int _iArray[_iSize]) {//{print values}
    printf("{");
    for (int i = 0; i < _iSize; i++) {
        printf("%d", _iArray[i]);
        if(i < _iSize - 1) {
            printf(",");
        }
    }
    printf("}\n");
}// end printArray

void randomizeArray(int _iSize, int _iArray[_iSize]) {//{random values}

    int iSum = 0;
    srand(time(NULL));

    for (int i = 0; i < _iSize; i++) {
        _iArray[i] = rand() % 10; // Random values between 0 and 9
        iSum += _iArray[i];
    }// end for

    printArray(_iSize, _iArray);
    printf("Sum: %d\n", iSum);

}// end randomizeArray

void uninitializeArray(int _iSize, int _iArray[_iSize]) {//{uninitialized values}
    printArray(_iSize, _iArray);
}// end uninitializeArray
