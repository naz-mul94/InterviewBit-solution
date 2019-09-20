/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(!A||!A->next)return A;
    if(B==1)return A;
    ListNode* prev=NULL;
    ListNode* cur=A;
    ListNode* next=A->next;
    ListNode* head, *set_head=NULL, *tail=NULL;
    int temp=1, j;
    while(cur)
    {
        head=cur;
        for(j=1;j<=B;j++)
        {
            if(!prev)
            {
                prev=cur;
                cur=cur->next;
                next=cur->next;
                
            }
            else
            {
                cur->next=prev;
                prev=cur;
                cur=next;
                if(cur)
                next=cur->next;
            }
        }
        if(!set_head)set_head=prev;
        else
        {
            tail->next=prev;
        }
        head->next=cur;
        tail=head;
        prev=NULL;
        
    }
    return set_head;
}
########################################## method 2######################################################
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(!A)return A;
    ListNode *head1;
    ListNode *newHead=new ListNode(0);
    newHead->next=A;
    ListNode* temp=A;
    stack<int> bucket;
    while(temp)
    {
        head1=temp;
        for(int i=0;i<B;i++)
        {
            bucket.push(temp->val);
            temp=temp->next;
        }
        while(!bucket.empty())
        {
            head1->val=bucket.top();
            bucket.pop();
            head1=head1->next;
        }
    }
    return newHead->next;
}
