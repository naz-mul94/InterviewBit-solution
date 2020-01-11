/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Note: Follow 1st method always.
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

################################## different method ###################################################
vector<int> Solution::postorderTraversal(TreeNode* root) 
{
    vector<int> ans;// for storing the result
    stack<TreeNode*> st;
    TreeNode* temp, *current;// temp for storing intermediate node and current for traversing the tree
    if(!root)return ans;// checking root null or not
    if(root->left)// if left Node present, go to left side
    {
        current=root->left;
        root->left=NULL;
        st.push(root);
    }
    else if(root->right)// if right node present, traverse towards right side
    {
        current=root->right;
        root->right=NULL;
        st.push(root->right);
    }
    else//if there is no child
    {
        ans.push_back(root->val);
        return ans;
    }
    
    while(!st.empty() || current)
    {
        if(current->left)
        {
            temp=current->left;
            current->left=NULL;
            st.push(current);
            current=temp;
        }
        else if(current->right)
        {
            temp=current->right;
            current->right=NULL;
            st.push(current);
            current=temp;
        }
        else
        {
            ans.push_back(current->val);
            if(!st.empty())
            {
                current=st.top();
                st.pop();
            }
            else
            current=NULL;
        }
    }
    return ans;
}

