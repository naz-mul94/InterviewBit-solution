/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(!A){if(!B)return 1;else return 0;}
    if(!B)if(A)return false;
    if(A->val!=B->val)return 0;
    return (isSameTree(A->left, B->left)&&isSameTree(A->right, B->right));
}
