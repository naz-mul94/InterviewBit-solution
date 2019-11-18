int Solution::maxProfit(const vector<int> &A) 
{
    if(A.size()==0|| A.size()==1)return 0;
    int low=A[0];
    int ans=0;
    for(int i=0;i<A.size();i++)
    {
        low=min(low, A[i]);
        ans=max(ans, A[i]-low);
    }
    return ans;
}
