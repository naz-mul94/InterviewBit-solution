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
 map<int, int> nodeIndex;
 TreeNode* construct( vector<int> &A, int startIndex, int endIndex, vector<int> &B)
 {
     int present=rootIndex;
     if(startIndex>endIndex)return NULL;
     if(startIndex==endIndex)
     {
         TreeNode* root=new TreeNode(A[rootIndex++]);
         return root;
     }
     TreeNode* root=new TreeNode(A[rootIndex++]);
     root->left=construct( A, startIndex, nodeIndex[A[present]]-1, B);
     root->right=construct(A, nodeIndex[A[present]]+1, endIndex, B);
     return root;
 }

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    rootIndex=0;
    nodeIndex.clear();
    for(int i=0;i<A.size();i++)
    {
        nodeIndex[B[i]]=i;
    }
    TreeNode* root=new TreeNode(A[rootIndex++]);
    if(A.size()==1)return root;
    root->left=construct(A, 0, nodeIndex[A[0]]-1,B );
    root->right=construct(A, nodeIndex[A[0]]+1, B.size()-1 ,B);
    return root;
}
