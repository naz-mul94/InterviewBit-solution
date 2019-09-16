/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unordered_map<ListNode *, int> node;
    while(A)
    {
        if(node.find(A)!=node.end())
        return A;
        else
        node[A]=1;
        A=A->next;
    }
    return 0;
    
}
*** you could improve space complexity in O(1).follow floyd cycle detection algo.
https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/
