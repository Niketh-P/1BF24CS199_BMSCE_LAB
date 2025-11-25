#include<stdio.h>
#include<stdlib.h>




struct node{
    int data;
    struct node* next;
};
struct node* head=NULL, *head2=NULL;

void create_node(int n) {
    int d;
    struct node *newNode, *temp;


    head = NULL; 

    for(int i = 0; i < n; i++) {

        newNode = (struct node*)malloc(sizeof(struct node));
        
        printf("Enter data: \n");
        scanf("%d", &d);
        
        newNode->data = d;
        newNode->next = NULL; 
        

        if (head == NULL) {
            head = newNode;
            temp = newNode; 
        } 
        else {

            temp->next = newNode;
            temp = newNode;
        }
    }
}

void create_node2(int n) {
    int d;
    struct node *newNode, *temp;


    head2 = NULL; 

    for(int i = 0; i < n; i++) {

        newNode = (struct node*)malloc(sizeof(struct node));
        
        printf("Enter data: \n");
        scanf("%d", &d);
        
        newNode->data = d;
        newNode->next = NULL; 
        

        if (head2 == NULL) {
            head2 = newNode;
            temp = newNode; 
        } 
        else {

            temp->next = newNode;
            temp = newNode;
        }
    }
}


void sort(){
    int tempdata;
    struct node* i, *j;
    for(i=head;i->next!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data > j->data){
                tempdata=i->data;
                i->data = j->data;
                j->data = tempdata;
            }
        }
    }
}


void reverse(){
    struct node *next=NULL, *prev=NULL;
    struct node *curr;
    curr=head;
    while (curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head = prev;
}


void concatenate(){
    int n;
    printf("Enter the size of the new linked list: \n");
    scanf("%d",&n);
    create_node2(n);
    struct node* temp=head;
    while (temp->next != NULL) {
            temp = temp->next;
    } 
    temp->next=head2;  
}

void display(){
    struct node* temp=head;
    if (head==NULL){
        printf("Empty list");
        return;
    }else{
        while(temp!=NULL){
            printf("%d, ",temp->data);
            temp=temp->next;
        }
        printf("\n");
        return;
    }
}


void main(){
    int choice,n;
    printf("Enter the size of the first linked list: \n");
    scanf("%d",&n);
    
    do
    {
        printf("Enter your choice \n");
        printf("1. create a linked list \n");
        printf("2. sort the list \n");
        printf("3. reverse \n");
        printf("4. concatenate a new list \n");
        printf("5. display \n");
        printf("6. EXIT \n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                create_node(n);
                break;
            case 2:
                sort();
                break;
            case 3:
                reverse();
                break;
            case 4:
                concatenate();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;

            
        }
    } while (1);
    
}
