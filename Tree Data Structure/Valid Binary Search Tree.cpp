
int valid(TreeNode* root, int min, int max)
{
    if(!root)return 1;
    if(root->val<=min || root->val >=max)return 0;
    if(valid(root->left, min, root->val)&&valid(root->right, root->val, max))
    {//cout<<"here:"<< root->val;
    return 1;
    }
    return 0;
}
int Solution::isValidBST(TreeNode* A) {
    if(!A)return 1;
    if(valid(A, INT_MIN, INT_MAX))
    return 1;
    return 0;
}
