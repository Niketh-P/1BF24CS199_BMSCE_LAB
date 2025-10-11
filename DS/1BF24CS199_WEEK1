#include <stdio.h>
#include <conio.h>
#define N 5
int stack[N];
int top=-1;
void push(){
    int x;
    if (top>=N)
    {
        printf("Stack Overflow \n");
    }
    else{
        printf("Enter the ele: \n");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop(){
    int temp;
    if (top==-1){
        printf("Stack Underflow \n");
    }
    else{
        temp=stack[top];
        printf("Deleted ele: %d \n",temp);
        top--;
    }
}
void display(){
    if (top==-1)
    {
        printf("Empty Stack \n");
    }
    else{
        int i=0;
        while(i<N){
            printf("%d ",stack[i]);
            if(i==top){
                break;
            }
            i++;
        }
    }
}
void peek(){
    if (top==-1)
    {
        printf("Empty Stack \n");
    }
    else{
        printf("Top ele: %d \n",stack[top]);
    }
}
void main()
{
    int choice;
    while(1){
        printf("Enter your choice: 1.push 2.pop 3.display 4.peek 5.exit \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid option! try again \n ");

        }
    }
}

