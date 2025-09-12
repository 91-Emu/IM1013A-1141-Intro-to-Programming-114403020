#include <stdio.h>

//function main begins program execution
int main(void){
    int integer1;//1st int entered by user
    int integer2;//2nd int entered by user

    printf("enter 1st integer\n");//prompt user enter 1st integer
    scanf("%d", &integer1);//read 1st integer from user
    printf("enter 2nd integer\n");//prompt user enter 2nd integer
    scanf("%d", &integer2);//read 2nd integer from user
    int sum;//variable in which sum is stored
    sum = integer1 + integer2;//sum of integer1 and integer2
    printf("sum is %d\n", sum);//print sum

}//end function main