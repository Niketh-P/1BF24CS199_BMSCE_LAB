#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node* createNode(int value){
    struct node* newNode= (struct node*) malloc(sizeof(struct node));
    newNode->data=value;
    newNode->right=NULL;
    newNode->left=NULL;
}

struct node* insert(struct node* root, int value){
    if(root==NULL){
        return createNode(value);
    }
    if(value<root->data){
        root->left=insert(root->left,value);
    }else if(value>root->data){
        root->right=insert(root->right,value);
    }
    return root;

}


void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node* root){
    if (root == NULL){ 
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if (root == NULL){ 
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void display(struct node* root){
    printf("BST elements: ");
    inorder(root);
    printf("\n");
}

int main(){
    struct node *root=NULL;
    int choice, value;

    while(1){
        printf("\n");
        printf("1. Insert into BST \n");
        printf("2. Inorder Transversal \n");
        printf("3. Preorder Transversal \n");
        printf("4. Postorder Transversal\n");
        printf("5. Display BST\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to be printed: ");
                scanf("%d", &value);
                root=insert(root,value);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                display(root);
                break;
            case 6:
                printf("Exiting...");
                exit(0);
    
        }
    }
}
