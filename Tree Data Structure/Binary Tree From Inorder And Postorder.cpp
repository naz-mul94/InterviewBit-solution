/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int rootIndex;
 unordered_map<int, int> index2;
TreeNode* construct(vector<int> &A, int startIndex, int endIndex, vector<int> &B)
{
    int present=rootIndex;
    if(endIndex<startIndex)return NULL;
    if(startIndex==endIndex)
    {
        TreeNode* root= new TreeNode(B[rootIndex--]);
        return root;
    }
    TreeNode* root=new TreeNode(B[rootIndex--]);
    root->right=construct(A, index2[B[present]] + 1, endIndex, B);
    root->left=construct(A, startIndex, index2[B[present]] - 1, B);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    index2.clear();
    rootIndex=B.size()-1;
    for(int i=0;i<A.size();i++)
    {
        index2[A[i]]=i;
    }
    TreeNode *root=new TreeNode(B[rootIndex--]);
    if(A.size()==1)return root;
    root->right=construct(A, index2[B[B.size()-1]] + 1, A.size()-1, B);
    root->left=construct(A, 0, index2[B[B.size()-1]]-1, B);
    return root;
}
