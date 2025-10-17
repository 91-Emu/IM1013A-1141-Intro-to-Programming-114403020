#include<stdio.h>
int main(void){
    puts("==== Future City Tech Expo Ticket System ====");
    puts("1) Option 1 - Single-Order Quotation");
    puts("2) Option 2 - Group Total & Installments");
    puts("(-1) End program");

    int iOption=-1;
    printf("Select: ");
    scanf("%d",&iOption);

    puts("\n");

    int iAdults=0, iStudents=0;
    int iTotalTickets=0;
    float fBaseTotal=0;
    float fQuantityDiscountFactor=0;
    float fMultipleOf5Factor=1.00;
    float fFinalPayableAmount=0;

    while(iOption != -1){
        if(iOption==1){

            printf("%s","[Option 1] Enter number of adults (1-20), or -1 to end: ");
            scanf("%d",&iAdults);
            if(iAdults==-1){
                iOption=-1;
                puts("Program ends.");
            }
            else if(iAdults<1 || iAdults>20){
                puts("Invalid number of adults. Please enter a number between 1 and 20.");
            }

            printf("%s","[Option 1] Enter number of students (1-20), or -1 to end: ");
            scanf("%d",&iStudents);
            if(iStudents==-1){
                iOption=-1;
                puts("Program ends.");
            }
            else if(iStudents<1 || iStudents>20){
                puts("Invalid number of students. Please enter a number between 1 and 20.");
            }

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
            
        }//end if option 1

        else if(iOption==2){
    
        }//end else if option 2

        else if(iOption==-1){
    
            puts("Program ends.");
    
        }//end else if option -1

        else{

            puts("Unknown selection. Please choose 1, 2, or -1 to end.");
    
        }//end else unknown option

    }//end while option not -1

}//end main