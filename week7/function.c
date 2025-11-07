#include <stdio.h>

double multiply(double _num1, double _num2);
double divide(double _num1, double _num2);
double BMI(int _weight_in_kg, double _height_in_m);

int main(){

    int weight_in_kg;
    double height_in_cm;
    double height_in_m;

    puts("Please enter your weight in kg:");
    scanf("%d",&weight_in_kg);
    puts("Please enter your height in cm:");
    scanf("%lf",&height_in_cm);
    height_in_m = divide(height_in_cm,100);

    printf("Your BMI is: %.2f\n",BMI(weight_in_kg,height_in_m));

}//end main

double multiply(double _num1, double _num2){
    double fResult = _num1 * _num2;
    return fResult;
}//end multiply

double divide(double _num1, double _num2){
    double fResult = _num1/_num2;
    return fResult;
}//end divide

double BMI(int _weight_in_kg, double _height_in_m){
    double fBMI = divide(_weight_in_kg,(multiply(_height_in_m,_height_in_m)));
    return fBMI;
}//end BMI

