/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode *> bucket;
    if(A==NULL)return ans;
    TreeNode *current=A;
    bucket.push(A);
    while(!bucket.empty())
    {
        TreeNode *temp=bucket.top();
        if(temp)
        {
            if(temp->left)
            {
                bucket.push(temp->left);
                temp->left=NULL;
            }  
            else if(temp->right)
            {
                bucket.push(temp->right);
                temp->right=NULL;
            }
            else
            {
                ans.push_back(temp->val);
                bucket.pop();
            }
        }
        
        
    }
    return ans;
}
