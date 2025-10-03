#include<stdio.h> 
#include<math.h>

/*
Application: Compound-Interest Calculations
• Consider the following problem statement:
– A person invests $1000.00 in a savings account yielding 5%
interest. Assuming that all interest is left on deposit in the account,
calculate and print the amount of money in the account at the end
of each year for 10 years. Use the following formula for determining
these amounts:
a = p(1 + r)n
where
p is the original amount invested (i.e., the principal)
r is the annual interest rate
n is the number of years
a is the amount on deposit at the end of the nth year
*/

int main(void){

    double principal = -1;
    double rate = -1;
    int years = 0;
    double amount = 0;
    int iCount = 0;

    while(principal < 0){
        puts("Please enter the principal:");
        scanf("%lf",&principal);
        if(principal < 0){
            puts("Principal must be >= 0");
        }
    }//end while
    while(rate < 0){
        puts("Please enter the rate(5.5 means 5.5%):");
        scanf("%lf",&rate);
        if(rate < 0){
            puts("Rate must be >= 0");
        }
    }//end while
    rate /= 100;
    while(years < 1){
        puts("Please enter the number of years(integer):");
        scanf("%d",&years);
        if(years < 1){
            puts("Years must be >= 1");
        }
    }//end while

    printf("%4s%21s\n","Year","Amount on deposit");

    for(iCount = 1; iCount <= years; iCount++){
        amount = principal * pow((1 + rate),iCount);
        printf("%4u%21.2f\n",iCount,amount);
    }//end for
    
}//end main