/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* make_tree(const vector<int> &A, int start, int end)
 {
     int len=end-start+1;
     if(len==0)return NULL;
     if(len==1)
     {
         TreeNode *temp=new TreeNode(A[start]);
         return temp;
     }
     int mid= (len+1)/2;
     int index=start+mid-1;
     TreeNode *temp=new TreeNode(A[index]);
     temp->left=make_tree(A,start, index-1);
     temp->right=make_tree(A,index+1, end);
     return temp;
 }
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode* root=make_tree(A, 0, A.size()-1);
    return root;
}
