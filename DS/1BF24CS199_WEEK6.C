#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void createlist(int n)
{
    struct Node *newNode, *temp;
    int data,i;

    if(n<0){
        printf("The entered number should be greater than 0");
        return;
    }else{
        for(i=0;i<n;i++){
            newNode=(struct Node*)malloc(sizeof(struct Node));
            if (newNode==NULL){
                printf("Memory allocation failed");
                return;
            }
            printf("Enter data for the node: \n");
            scanf("%d",&data);
            newNode->data=data;
            newNode->next=NULL;

            if(head==NULL){
                head=newNode;
            }else{
                temp->next=newNode;
            }
            temp=newNode;
        }
        printf("List created");
    }
}


void deleteFirst(){
    struct Node *temp;
    if (head==NULL){
        printf("Empty list");
        return;
    }else{
        temp=head;
        head=head->next;
        printf("Deleted ele= %d",temp->data);
        free(temp);
    }
}


void deleteLast(){
    struct Node *temp=head,*prev;
    if (head==NULL){
        printf("Empty list");
        return;
    }else if(head->next==NULL){
        printf("deleted ele= %d",head->data);
        free(head);
        head=NULL;
        return;
    }
    else{
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        printf("deleted ele= %d",temp->data);
        free(temp);
    }
}

void deleteVal(int val){
    struct Node *temp=head,*prev=NULL;
    if (head==NULL){
        printf("Empty list");
        return;
    }else if(head->data==val){
        head=head->next;
        printf("deleted %d",temp->data);
        free(temp);
        return;
    }else{
        temp=head;
        prev=NULL;
        while(temp->data!=val&&temp!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        printf("deleted %d",temp->data);
        free(temp);
        return;
    }
}


void display(){
    struct Node* temp=head;
    if (head==NULL){
        printf("Empty list");
        return;
    }else{
        while(temp!=NULL){
            printf("%d, ",temp->data);
            temp=temp->next;
        }
        return;
    }
}


void main(){
    int choice,value,n;
    
    printf("1. create list \n");
    printf("2. delete from first \n");
    printf("3. delete from last \n");
    printf("4. delete val \n");
    printf("5. display list \n");
    printf("6. exit \n");
    while(1){
        printf("Enter your choice: \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("enter the number of nodes: \n");
            scanf("%d",&n);
            createlist(n);
            break;
        case 2:
            deleteFirst();
            break;
        case 3:
            deleteLast();
            break;
        case 4:
            printf("Enter the value to be deleted: \n");
            scanf("%d",&value);
            deleteVal(value);
            break;
        case 5:
            printf("List: ");
            display();
            break;
        case 6:
            printf("exiting program...");
            exit(0);
            break;
        
        default:
            printf("Invalid choice");
            break;
        }
    }
}


