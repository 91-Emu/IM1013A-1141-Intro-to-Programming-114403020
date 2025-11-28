#include<stdio.h>
#define SIZE 5
int main() {
    int arr[SIZE]={0};
    for(int i=0;i<SIZE;i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
}