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
#########################  Solution 2 #####################################
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *less=NULL;
    ListNode* greater=NULL;
    ListNode* head, *head1;
    ListNode *temp=A;
    while(temp)
    {
        ListNode* temp1=temp->next;
        if(temp->val<B)
        {
            if(!less)
            {
                less=temp;
                head=temp;
                less->next=NULL;
            }
            else
            {
                less->next=temp;
                less=less->next;
                less->next=NULL;
            }
        }
        else
        {
            if(!greater)
            {
                greater=temp;
                head1=temp;
                greater->next=NULL;
            }
            else
            {
                greater->next=temp;
                greater=greater->next;
                greater->next=NULL;
            }
        }
        temp=temp1;
    }
    if(less)
    {
        less->next=head1;
        return head;
    }
    return head1;
    
}

