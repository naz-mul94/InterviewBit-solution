/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* findMid(ListNode* head)
 {
     if(!head||!head->next)return head;
     ListNode* slow=head;
     ListNode* fast=head->next;
     while(slow&&fast&&fast->next)
     {
         slow=slow->next;
         fast=fast->next->next;
     }
     return slow;
 }
ListNode* Merge(ListNode* l1, ListNode* l2)
 {
     if(!l2)return l1;
     if(!l1)return l2;
     ListNode* head;
     if(l1->val>l2->val)
     {
         head=l2;
         l2=l2->next;
     }
     else
     {
         head=l1;
         l1=l1->next;
     }
     ListNode* p=head;
     while(l1&&l2)
     {
         if(l1->val>l2->val)
         {
             p->next=l2;
             l2=l2->next;
         }
         else
         {
             p->next=l1;
             l1=l1->next;
         }
         p=p->next;
     }
     if(l1)
     {
         p->next=l1;
     }
     if(l2)
     {
         p->next=l2;
     }
     return head;
 }
ListNode* Solution::sortList(ListNode* A) {
    if(!A||!A->next)return A;
    ListNode* B=A->next;
    ListNode* mid=findMid(A);
    B= mid->next;
    mid->next=NULL;
    ListNode* l1=sortList(A); 
    ListNode* l2=sortList(B);
    return Merge(l1, l2);
     
}
