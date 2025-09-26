#include<stdio.h>
int main(void){
    int total=0;
    int studentcount=0;
    int score=-1;
    float average=0;
    int pass=0;
    int fail=0;

    int scoremin=0;
    int scoremax=100;

    puts("Plese enter the score of student 1 or -1 to end ");
    printf("(%d~%d):",scoremin,scoremax);
    scanf("%d",&score);

    while(score!=-1){
        while((score<scoremin||score>scoremax)&&score!=-1){
            puts("Invalid score, Please enter again");
            printf("(%d~%d):",scoremin,scoremax);
            scanf("%d",&score);
        }//end while
        if(score!=-1){
            studentcount++;
            total+=score;
            printf("%s%d%s\n","Plese enter the score of student ",studentcount+1," or -1 to end ");
            scanf("%d",&score);
            if(score>=60)
                pass++;
            else if(score>=0)
                fail++;
        }//end if
        
    }//end while

    average=(float)total/(studentcount);

    if (studentcount==0)
        puts("No data");
    else
        printf("total score of %d students is %d,\n",studentcount,total);
        printf("class average is %.2f\n",average);
        printf("number of pass is %d\n",pass);
        printf("number of fail is %d\n",fail);
}//end main        

    
    

