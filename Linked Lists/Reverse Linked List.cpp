
ListNode* Solution::reverseList(ListNode* A) {
    if(!A||!A->next)return A;
    ListNode* prev=NULL, *cur=A, *next=A->next;
    while(cur)
    {
        if(!prev)
        {
            prev=cur;
            cur=next;
            next=cur->next;
        }
        else
        {
            cur->next=prev;
            prev=cur;
            cur=next;
            if(cur)next=cur->next;
        }
    }
    A->next=NULL;
    return prev;
}
