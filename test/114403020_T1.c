#include<stdio.h>
#include<math.h>
int main(void){
    puts("==== Future City Tech Expo Ticket System ====");
    puts("1) Option 1 - Single-Order Quotation");
    puts("2) Option 2 - Group Total & Installments");
    puts("(-1) End program");

    int iOption=-1;
    printf("Select: ");
    scanf("%d",&iOption);

    int iAdults=0, iStudents=0;
    int iTotalTickets=0;
    float fBaseTotal=0;
    float fQuantityDiscountFactor=0;
    float fMultipleOf5Factor=1.00;
    float fFinalPayableAmount=0;
    float fPrincipal=0;
    
    if(iOption==-1){
        puts("Program ends.");
    }
    while(iOption != -1){
        if(iOption==1){

            printf("%s","[Option 1] Enter number of adults (1-20), or -1 to end: ");
            scanf("%d",&iAdults);
            if(iAdults==-1){
                iOption=-1;
                puts("\nProgram ends.");
            }
            else if(iAdults<1 || iAdults>20){
                puts("Invalid number of adults. Please enter a number between 1 and 20.");
            }

            printf("%s","[Option 1] Enter number of students (1-20), or -1 to end: ");
            scanf("%d",&iStudents);
            if(iStudents==-1){
                iOption=-1;
                puts("\nProgram ends.");
            }
            else if(iStudents<1 || iStudents>20){
                puts("Invalid number of students. Please enter a number between 1 and 20.");
            }

            if(iAdults>=1 && iAdults<=20 && iStudents>=1 && iStudents<=20){
                puts("");
                puts("--- Quotation Summary ---");
                iTotalTickets = iAdults + iStudents;
                printf("Adults: %d, Students: %d, Total Tickets: %d\n",iAdults,iStudents,iTotalTickets);
        
                if(iTotalTickets >=1 && iTotalTickets <=5){
                    fQuantityDiscountFactor = 1.00;
                }
                else if(iTotalTickets >=6 && iTotalTickets <=10){
                    fQuantityDiscountFactor = 0.95;
                }
                else if(iTotalTickets >=11 && iTotalTickets <=15){  
                    fQuantityDiscountFactor = 0.90;
                }
                else if(iTotalTickets >=16){
                    fQuantityDiscountFactor = 0.85;
                }
                else{
                    puts("wrong");
                    iOption=-1;
                }

                fBaseTotal = (iAdults * 200 + iStudents * 150);
                printf("Base Total: %.2f\n",fBaseTotal);
                printf("Quantity Discount Factor: %.2f\n",fQuantityDiscountFactor);

                if(iTotalTickets%5==0){
                puts("Multiple-of-5 Bonus Applied: Yes (Factor: 0.95)");
                fMultipleOf5Factor = 0.95;
                }//end if %5

                else{   
                puts("Multiple-of-5 Bonus Applied: No (Factor: 1.00)");
                fMultipleOf5Factor = 1.00;
                }//end else %5

                fFinalPayableAmount = fBaseTotal * fQuantityDiscountFactor * fMultipleOf5Factor;
                printf("Final Payable Amount: %.2f\n\n",fFinalPayableAmount);

            }//end if adults and students valid

            
        }//end if option 1

        else if(iOption==2){

            /*
            a. <500: no installments offered. 
            b. 500-1000: 3 monthly installments, handling fee 20 per installment,monthly interest rate 3% 
            c. 1001-2000: 6 monthly installments, handling fee 17 per installment, monthly interest rate 2.5% 
            d. >2000: 12 monthly installments, handling fee 12 per installment, monthly interest rate 1.5%
            principal: 1000.00
            number of periods: 3
            handling fee per period: 20.00
            monthly interest rate: 3.00%
            Repayment (compound on principle): 1092.73
            total handing fee: 60.00
            total payable amount: 1152.73
            payment per installment: 384.24
            */

            printf("%s","[Option 2] Enter principal in dollars (positive), or -1 to end: ");
            scanf("%f",&fPrincipal);
            if(fPrincipal==-1){
                iOption=-1;
                puts("\nProgram ends.");
            }
            else if(fPrincipal<=0){
                puts("Invalid principal amount. Please enter a positive amount.");
            }
            else{

                int iNumPeriods=0;
                float fHandlingFeePerPeriod=0;
                float fMonthlyInterestRate=0;
                if(fPrincipal<500){
                    iNumPeriods=1;
                }//end if principal<500

                else if(fPrincipal>=500 && fPrincipal<=1000){
                    iNumPeriods=3;
                    fHandlingFeePerPeriod=20.00;
                    fMonthlyInterestRate=3.00;
                }//end else if 500-1000

                else if(fPrincipal>=1001 && fPrincipal<=2000){
                    iNumPeriods=6;
                    fHandlingFeePerPeriod=17.00;
                    fMonthlyInterestRate=2.50;
                }//end else if 1001-2000

                else if(fPrincipal>2000){
                    iNumPeriods=12;
                    fHandlingFeePerPeriod=12.00;
                    fMonthlyInterestRate=1.50;
                }//end else if >2000
                
                float fRepayment = fPrincipal; //store original principal for output
                for(int i=0; i<iNumPeriods; i++){
                    fRepayment = fRepayment * (1 + fMonthlyInterestRate/100);
                }
                float fTotalHandlingFee = fHandlingFeePerPeriod * iNumPeriods;
                float fTotalPayableAmount = fRepayment + fTotalHandlingFee;
                float fPaymentPerInstallment = fTotalPayableAmount / iNumPeriods;
                puts("");
                puts("--- Installment Summary ---");
                printf("Principal: %.2f\n",fPrincipal);
                printf("Number of periods: %d\n",iNumPeriods);
                printf("Handling fee per period: %.2f\n",fHandlingFeePerPeriod);
                printf("Monthly interest rate: %.2f%%\n",fMonthlyInterestRate);
                printf("Repayment (compound on principle): %.2f\n",fRepayment);
                printf("Total handing fee: %.2f\n",fTotalHandlingFee);
                printf("Total payable amount: %.2f\n",fTotalPayableAmount);
                printf("Payment per Installment: %.2f\n\n",fPaymentPerInstallment);
            
            }//end else principal valid


        }//end else if option 2

        else if(iOption==-1){
    
            puts("Program ends.");
    
        }//end else if option -1

        else{

            puts("Unknown selection. Please choose 1, 2, or -1 to end.");
            puts("");
            puts("==== Future City Tech Expo Ticket System ====");
            puts("1) Option 1 - Single-Order Quotation");
            puts("2) Option 2 - Group Total & Installments");
            puts("(-1) End program");
            printf("Select: ");
            scanf("%d",&iOption);
    
        }//end else unknown option

    }//end while option not -1

}//end main