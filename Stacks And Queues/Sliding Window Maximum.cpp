/*
int max_element(const vector<int> &A, int first, int end)
{
    
}
*/
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> ans;
    deque<int> que;
    int i;
    if(A.size()==B||B>A.size())
    {
        int x=*max_element(A.begin(), A.end());
        ans.push_back(x);
        return ans;
    }    
    for(i=0;i<B;i++)
    {
        while(!que.empty()&&(A[que.back()]<=A[i]))
        {
            que.pop_back();
        }
        que.push_back(i);
    }
    
    
    for(i=B;i<A.size();i++)
    {
        ans.push_back(A[que.front()]);
        while(!que.empty()&&que.front()<=(i-B))
        que.pop_front();
        
        while(!que.empty()&&(A[que.back()]<=A[i]))
        {
            que.pop_back();
        }
        que.push_back(i);
        
    }
    ans.push_back(A[que.front()]);
    return ans;
}
