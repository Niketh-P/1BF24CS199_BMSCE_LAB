#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

struct node* createnode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void createList(int n) {
    int val;
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val); // Removed trailing space
        struct node* newNode = createnode(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}

void insertatBegin(int val) {
    struct node* newNode = createnode(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at beginning.\n", val);
}

// Insert val1 to the left of val2
void insertLeft(int val1, int val2) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Edge case: If the target (val2) is the head, we are inserting at begin
    if (head->data == val2) {
        insertatBegin(val1);
        return;
    }

    struct node* newNode = createnode(val1);
    struct node* temp = head;

    // Fixed loop order to prevent crash
    while (temp != NULL && temp->data != val2) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not present in list.\n", val2);
        free(newNode); // Clean up unused memory
        return;
    }

    // Linking logic
    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev = newNode;
    printf("Inserted %d to the left of %d.\n", val1, val2);
}

void deleteBegin() {
    if (head == NULL) {
        printf("Empty list.\n");
        return;
    }
    
    struct node* temp = head;
    
    // Fixed: used == for comparison
    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL; // Fixed: Assignment, not comparison
    }
    
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

void deletePos(int pos) {
    if (head == NULL) {
        printf("Empty list.\n");
        return;
    }

    if (pos == 1) {
        deleteBegin();
        return;
    }

    int p = 1;
    struct node* temp = head;
    
    while (p < pos && temp != NULL) {
        temp = temp->next;
        p++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    } 
    
    // Deleting the tail
    if (temp == tail) {
        tail = temp->prev;
        tail->next = NULL;
        printf("Deleted %d (tail).\n", temp->data);
        free(temp);
        return;
    }

    // Deleting in the middle
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    printf("Deleted %d from position %d.\n", temp->data, pos);

    free(temp);
}

void deleteVal(int val) {
    if (head == NULL) {
        printf("Empty list.\n");
        return;
    }
    if (head->data == val) {
        deleteBegin();
        return;
    }

    struct node* temp = head;
    
    
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d does not exist.\n", val);
        return;
    }

    
    if (temp == tail) {
        tail = temp->prev;
        tail->next = NULL;
        printf("Deleted %d (tail).\n", temp->data);
        free(temp);
        return;
    }

    // Middle deletion
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    printf("Deleted value %d.\n", temp->data);

    free(temp);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int ch, val, n, val2;
    while (1) {
        printf("\n-----------------\n");
        printf("1. Create list\n2. Insert left\n3. Delete at position\n4. Delete by value\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch); 
        
        switch (ch) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                printf("Enter the value of the EXISTING node to insert left of: ");
                scanf("%d", &val2);
                insertLeft(val, val2);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &n);
                deletePos(n);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteVal(val);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
