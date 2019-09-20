/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 vector<vector<int>> ans;
 void check(vector<vector<int>> &ans, vector<int> temp, TreeNode* A, int B, int sum)
 {
     sum+=A->val;
     temp.push_back(A->val);
     if(!A->left&&!A->right)
     {
         if(sum==B)
         {
             ans.push_back(temp);
         }
         return;
     }
     if(A->left)
     check(ans, temp, A->left, B, sum);
     if(A->right)
     check(ans, temp, A->right, B, sum);
     
 }
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    ans.clear();
    int sum=0;
    if(!A)return ans;
    vector<int> temp;
    check(ans, temp, A, B, sum);
    return ans;
}
