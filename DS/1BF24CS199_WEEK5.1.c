/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* temp1=head;
    struct ListNode* temp2=head;
    int n=1;

    if (head=NULL){
        printf("Empty list");
        return (NULL);
    }
    else{
        while(temp1->next!=NULL){
            temp1=temp1->next;
            n++;
        }
        int m=(n/2)+1;
        for(int i=1;i<m;i++){
            temp2=temp2->next;
        }
        return(temp2);
    }

}
