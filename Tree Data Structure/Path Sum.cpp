/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 int ans;
 void check(TreeNode* A, int B, int sum)
 {
     sum+=A->val;
     if(!A->left&&!A->right)
     {
         if(sum==B)
         ans=1;
         return;
     }
     if(A->left&&!ans)
     check(A->left, B, sum);
     if(A->right&&!ans)
     check(A->right, B, sum);
 }
int Solution::hasPathSum(TreeNode* A, int B) {
    int sum=0;
    ans=0;
    if(!A)return 0;
    check(A, B, sum);
    return ans;
}
