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

    if(iOption==1){

        printf("%s","[Option 1] Enter number of adults (1-20), or -1 to end: ");
        scanf("%d",&iAdults);
        printf("%s","[Option 1] Enter number of students (1-20), or -1 to end: ");
        scanf("%d",&iStudents);

        puts("--- Quotation Summary ---");
        iTotalTickets = iAdults + iStudents;
        printf("Adults: %d, Students: %d, Total Tickets: %d\n",iAdults,iStudents,iTotalTickets);
        
        if(iTotalTickets >=1 && iTotalTickets <=5){


        }
        else if(iTotalTickets >=6 && iTotalTickets <=10){
            
        }
        else if(iTotalTickets >=11 && iTotalTickets <=15){  
            
        }
        else if(iTotalTickets >=16){
            puts("Invalid number of tickets. Please enter a total between 1 and 20.");
        }

    }//end if option 1

    else if(iOption==2){
    
    }//end else if option 2

    else if(iOption==-1){
    
        puts("Program ends.");
    
    }//end else if option -1

    else{

        puts("Unknown selection. Please choose 1, 2, or -1 to end.");
    
    }//end else unknown option
}