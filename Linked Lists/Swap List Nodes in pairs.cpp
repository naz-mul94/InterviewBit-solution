/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(!A)return A;
    ListNode* prev=NULL, *cur=A, *next;
    ListNode* front, *head=NULL, *tail=NULL;
    int i;
    while(cur)
    {
        front=cur;
        for(i=1;i<=2&&cur;i++)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        if(!head)head=prev;
        else tail->next=prev;
        tail=front;
        prev=NULL;
        
    }return head;
}
