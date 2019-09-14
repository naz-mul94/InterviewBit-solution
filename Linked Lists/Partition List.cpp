/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *head=A;
    ListNode* cur=NULL;
    ListNode* prev=NULL;
    ListNode *temp=A;
    while(temp)
    {
        if(temp->val<B)
        {
            ListNode* temp1;
            if(prev)
            {
                
                prev->next=temp->next;
                if(!cur)
                {
                    cur=temp;
                    temp->next=head;
                    head=cur;
                }
                else
                {
                    temp1=cur->next;
                    cur->next=temp;
                    temp->next=temp1;
                    cur=cur->next;
                }
                temp=prev->next;
            }
            else
            {
                cur=temp;
                temp=temp->next;
            }
            
            
        }
        else
        {
            prev=temp;
            temp=temp->next;
        }
        
    }return head;
    
    
}
