#include<stdio.h>
#include<stdlib.h>




struct node{
    int data;
    struct node* next;
};
struct node* head, *newNode;

void create_node(int n){
    int d;
    for(int i=0;i<n;i++){
        struct node* head, *newNode, *temp;
        newNode=(struct node*)malloc(sizeof(struct node*));
        printf("Enter data: \n");
        scanf("%d",&d);
        newNode->data=d;
        newNode->next=0;
        head=temp;
        
        if (head==0){
            head=temp=newNode;
        }

        else{
            temp->next=newNode;
            temp=newNode;
        }

    }
}

void display(){
    struct node* temp=head;
    if(head==NULL){
        printf("Empty list");
    }

    printf("\n Linked list: ");
    while(temp!=NULL){

        printf(" %d",temp->data);
        temp->next=temp;
    
    }
    printf(" %d",temp->data);
}

void insert_first(int d){
    struct node* head, *newNode, *temp;
    newNode=(struct node*)malloc(sizeof(struct node*));
    newNode->data=d;
    newNode->next=head;
    head=newNode;
    printf("Insertion completed.");
}

void insert_last(int d){
    struct node* head, *newNode;
    struct node* temp=head;
    newNode=(struct node*)malloc(sizeof(struct node*));
    if(head==NULL){
        head=newNode;
    }
    else{
        while (temp->next!=NULL)
        {
            temp->next=temp;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        printf("Insertion completed.");
        
    }

}

void insertatpos(int d, int pos){
    struct node* head, *newNode;
    struct node* temp=head;
    newNode=(struct node*)malloc(sizeof(struct node*));
    if(head==NULL){
        printf("Empty list");
        return;
    }
    else{
        for(int i=0;i<pos && temp!=NULL;i++){
            temp->next=temp;
        }
        if(temp==NULL){
            printf("pos is out of range.");       
            return;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        printf("Insertion completed.");
    }
}

    
    


void main(){
    struct node;
    struct node* head, *newNode, *temp;
    int d,choice,pos,n;
    printf("Enter the number of nodes in the linked list: \n");;
    scanf("%d", &n);
    create_node(n);
    while(n!=0){
        printf("Enter your choice: \n");
        printf("1-> insert at beginning \n");
        printf("2-> insert at end \n");
        printf("3-> insert at position \n");
        printf("4-> display \n");
        printf("5-> exit \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d",&d);
            insert_first(d);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d",&d);
            insert_last(d);
            break;

        case 3:
            printf("Enter data: \n");
            scanf("%d",&d);
            printf("Enter the position: \n");
            scanf("%d",&pos);
            insertatpos(d,pos);
            break;
        
        case 4:
            display();
            break;
        
        case 5:
            exit(0);
        }


    }


    
}
