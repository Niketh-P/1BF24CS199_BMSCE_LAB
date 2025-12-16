//CIRCULAR QUEUE

#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enqueue(int x){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%N==front){
        printf("Queue is full \n");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue(){
    if(front==-1&&rear==-1){
        printf("Queue is empty");
    }
    else if(front==rear){
        printf("Deleted element=%d \n",queue[front]);
        front=rear=-1;
    }
    else{
        printf("Deleted element=%d \n",queue[front]);
        front=(front+1)%N;
    }
}
void display(){
    if(front==-1&&rear==-1){
        printf("Queue is empty \n");
    }
    else{
        int i=front;
        while(i<(rear+1)%N){
            printf("%d ",queue[i]);
            i=(i+1)%N;
        }
    }
}
int main(){
    int ch;
    printf("Enter your choice(1:insertion,2:deletion,3:display,0:stop):");
    scanf("%d",&ch);
    while(ch!=0){
        switch(ch){
            case 1:
            {
                int x;
                printf("Enter the element:");
                scanf("%d",&x);
                enqueue(x);
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            default:
            {
                printf("Invalid input!!");
                break;
            }
        }
        printf("Enter your choice(1:insertion,2:deletion,3:display,0:stop):");
        scanf("%d",&ch);
    }
}
