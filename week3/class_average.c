#include<stdio.h>
int main(void){
    int total=0;
    int studentcount=1;
    int score=-1;
    float average=0;

    puts("Plese enter the score of student 1 or -1 to end ");
    scanf("%d",&score);

    while(score!=-1){
        if(score<0)
            puts("Invalid score, Please enter a valid score");
        else if(score>100)
            puts("Invalid score, Please enter a valid score");
        else{
            total+=score;
            studentcount++;
            printf("%s%d%s\n","Plese enter the score of student ",studentcount," or -1 to end ");
            scanf("%d",&score);
        }
    }//end while

    average=(float)total/(studentcount-1);
    if (studentcount==1)
        puts("No data");
    else
        printf("total score of %d students is %d,\naverage score is %.2f\n",studentcount-1,total,average);
}//end main        

    
    

