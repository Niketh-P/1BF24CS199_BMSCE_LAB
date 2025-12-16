#include<stdio.h>
int front=-1;
int rear=-1;
#define N 5
int queue[N];
void enqueue(int x){
    if(front==-1&&rear==-1){
        rear=front=0;
        queue[rear]=x;
    }
    else if(rear==N-1){
        printf("Queue is full");
    }
    else {
        rear++;
        queue[rear]=x;
    }

}
void dequeue(){
    if(front==-1&&rear==-1){
        printf("queue is empty");
    }
    else if(front==rear){
        printf("Deleted element=%d",queue[front]);
        front=rear=-1;
    }
    
    else{ 
        printf("Deleted element=%d",queue[front]);
        front++;
    }
}
void display(){
    if(front==-1&&rear==-1){
        printf("queue is empty");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
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
        printf("\n");
        printf("Enter your choice(1:insertion,2:deletion,3:display,0:stop):");
        scanf("%d",&ch);
    }
}
