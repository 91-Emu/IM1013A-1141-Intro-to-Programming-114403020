#include<stdio.h>
int iSumlast=0;

int digit_sum(int);//1234 -> 1+2+3+4=10

int main(){
        
    puts("Please enter a positive integer");
    unsigned iN=0;
    scanf("%d", &iN);

    printf("sum is %d.\n", digit_sum(iN));
}

int digit_sum(int _iN){
    if(_iN == 0){
        return 0;
    }
    int iSum=0;
    iSumlast+=_iN%10;
    printf("%d %3d %6d\n",_iN%10,iSumlast,_iN/10);
    iSum=_iN%10 + digit_sum(_iN/10);
    return iSum;
}