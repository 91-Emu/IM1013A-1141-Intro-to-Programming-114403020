#include <stdio.h> 
int main(void){
    float ftempF;//temperature in fahrenheit
    float ftempC;//temperature in celsius
    printf("Enter temperature in celsius\n");//prompt user to enter temperature in celsius
    scanf("%f",&ftempC);//read temperature in celsius from user
    ftempF = (9.0/5.0)*ftempC + 32.0;//convert celsius to fahrenheit
    printf("Temperature in fahrenheit is %.2f\n",ftempF);//print temperature in fahrenheit

}