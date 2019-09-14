/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode *> current, processed;
    current.push(A);
    while(!current.empty())
    {
        swap(current, processed);
        
        if(current.empty())
        {
            while(!processed.empty())
            {
                TreeLinkNode *done=processed.front();
                processed.pop();
                if(done->left)
                current.push(done->left);
                if(done->right)
                current.push(done->right);
                
                if(processed.empty())done->next=NULL;
                else done->next=processed.front();
            }
            
            
        }
    }
}
