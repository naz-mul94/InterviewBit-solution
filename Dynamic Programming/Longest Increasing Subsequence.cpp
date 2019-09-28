int Solution::lis(const vector<int> &A) {
    if(A.size()==0)return 0;
    if(A.size()==1)return 1;
    int ans=0;
    vector<int> h(A.size(), 1);
    for(int i=1;i<A.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(A[j]<A[i]&&h[i]<(h[j]+1))
            {
                h[i]=h[j]+1;
            }
            
        }
        if(ans<h[i])
        ans=h[i];
    }
    return ans;
}
