#include<stdio.h>
int iSum=0;

int digit_sum(int);//1234 -> 1+2+3+4=10

int main(){
        
    puts("Please enter a positive integer");
    unsigned iN=0;
    scanf("%d", &iN);

    digit_sum(iN);
    printf("The digit sum of %d is %d\n", iN, digit_sum(iN));
}

int digit_sum(int _iN){
    if(_iN == 0){
        return 0;
    }
    iSum=_iN%10 + digit_sum(_iN/10);
    return iSum;
}