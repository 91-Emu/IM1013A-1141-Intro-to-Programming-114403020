#include <stdio.h> 
int main(void){
    float ftempF;//temperature in fahrenheit
    float ftempC;//temperature in celsius
    printf("Enter temperature in fahrenheit\n");//prompt user to enter temperature in fahrenheit
    scanf("%f,&ftempf");//read temperature in fahrenheit from user
    ftempC = (5/9) * (ftempF-32);//convert fahrenheit to celsius
    printf("temperature in celsius is %f\n", ftempC);//print temperature in celsius
}