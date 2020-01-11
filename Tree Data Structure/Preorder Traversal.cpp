/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode *> bucket;
    if(A==NULL)return ans;
    bucket.push(A);
    while(!bucket.empty())
    {
        TreeNode * temp=bucket.top();
        bucket.pop();
        ans.push_back(temp->val);
        if(temp->right)
        bucket.push(temp->right);
        
        if(temp->left)
        bucket.push(temp->left);
    }
    
    return ans;
}
