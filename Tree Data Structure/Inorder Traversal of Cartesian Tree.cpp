/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 unordered_map<int, int> indexNode;
 TreeNode* construct(vector<int> &A, int startIndex, int endIndex)
 {
     if(startIndex>endIndex)return NULL;
     if(startIndex==endIndex)
     {
         TreeNode* root=new TreeNode(A[startIndex]);
         return root;
     }
     int max_=*max_element(A.begin()+startIndex,A.begin()+endIndex+1);
     TreeNode* root=new TreeNode(max_);
     root->left=construct(A, startIndex, indexNode[max_]-1);
     root->right=construct(A, indexNode[max_]+1, endIndex);
     return root;
 }
TreeNode* Solution::buildTree(vector<int> &A) {
    int max_=*max_element(A.begin(), A.end());
    indexNode.clear();
    
    for(int i=0;i<A.size();i++)
    indexNode[A[i]]=i;
    
    TreeNode* root=new TreeNode(max_);
    if(A.size()==1)return root;
    root->left=construct(A, 0, indexNode[max_]-1);
    root->right=construct(A, indexNode[max_]+1, A.size()-1);
    return root;
    
}
