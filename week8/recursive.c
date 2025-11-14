#include<stdio.h>

int countdown(int);//5 -> 5 4 3 2 1

int main(){
    
    puts("Please enter a integer between 1 and 9");
    int iN=0;
    scanf("%d", &iN);

    while(iN < 1 || iN > 9){
        puts("Invalid input.");
        puts("Please enter a integer between 1 and 9");
        scanf("%d", &iN);
    }
    countdown(iN);
}

int countdown(int _iN){
    if(_iN == 0){
        return 0;
    }
    printf("%d\n", _iN);
    return countdown(_iN - 1);
}