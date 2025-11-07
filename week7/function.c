#include <stdio.h>

int multiply(int _num1, int _num2){
    return _num1 * _num2;
}//end multiply

double divide(int _num1, int _num2){
    return (double)_num1 / _num2;
}//end divide

double BMI(int _weight_in_kg, double _height_in_m){
    return divide(_weight_in_kg,(multiply(_height_in_m,_height_in_m)));
}//end BMI

int main(){

    int weight_in_kg;
    double height_in_cm;
    double height_in_m;

    puts("Please enter your weight in kg:");
    scanf("%d",&weight_in_kg);
    puts("Please enter your height in cm:");
    scanf("%lf",&height_in_cm);
    height_in_m = height_in_cm / 100;

    printf("Your BMI is: %.2f\n",BMI(weight_in_kg,height_in_m));

}//end main