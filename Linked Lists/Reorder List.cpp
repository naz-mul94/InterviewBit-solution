/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 ListNode* merge(ListNode* l1, ListNode* l2)
 {
     ListNode* matha=l1;
     bool choice=true;
     ListNode* head=l1;
     l1=l1->next;
     while(l1&&l2)
     {
         if(!choice)
         {
             head->next=l1;
             //head=head->next;
             l1=l1->next;
         }
         else
         {
             head->next=l2;
             l2=l2->next;
            // head=head->next;
         }
         head=head->next;
         choice=!choice;
     }
     
     if(l1)head->next=l1;
     else head->next=l2;
     return matha;
     
 }
 ListNode* reverse(ListNode* head)
 {
     if(!head->next)return head;
     ListNode *prev=head, *cur=head, *next=head->next,*temp;
     while(next)
     {
         temp=next->next;
         next->next=cur;
         cur=next;
         next=temp;
     }
     head->next=NULL;
     return cur;
 }
 
ListNode* Solution::reorderList(ListNode* A) 
{
    if(!A|| !A->next || !A->next->next)return A;
    ListNode *head=A, *slow=A, *fast=A;
    while(fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode *mid=slow->next;
    slow->next=NULL;
    ListNode* secondHalf=reverse(mid);
    ;
    return A=merge(A, secondHalf);
}
