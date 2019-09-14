/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    long long int x=0, y=0, z=0;
    long long int sum=0, carry=0;
    ListNode *temp, *temp1;
    if(!A)return B;
    if(!B)return A;
    temp=A;
    temp1=B;
    ListNode  *cur;
    sum=temp->val+temp1->val;
    ListNode *head=new ListNode(sum%10);
    carry=sum/10;
    cur=head;
    temp=temp->next;
    temp1=temp1->next;
    while(temp||temp1||carry)
    {
        if(temp&&temp1)
        {
            sum=temp->val+temp1->val+carry;
            ListNode *node=new ListNode(sum%10);
            carry=sum/10;
            cur->next=node;
            cur=cur->next;
            temp=temp->next;
            temp1=temp1->next;
        }
        else if(temp1)
        {
            sum=temp1->val+carry;
            ListNode *node=new ListNode(sum%10);
            carry=sum/10;
            cur->next=node;
            cur=cur->next;
            temp1=temp1->next;
        }
        else if(temp)
        {
            sum=temp->val+carry;
            ListNode *node=new ListNode(sum%10);
            carry=sum/10;
            cur->next=node;
            cur=cur->next;
            temp=temp->next;
        }
        else
        {
            ListNode *node=new ListNode(carry);
            carry=0;
            cur->next=node;
            cur=cur->next;
        }
        
    }
    return head;
    
}
