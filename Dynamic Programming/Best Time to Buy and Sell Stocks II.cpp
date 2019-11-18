int Solution::maxProfit(const vector<int> &A) 
{
    int n=A.size();
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        if(A[i]<A[i+1])ans+=A[i+1]-A[i];
    }
    return ans;
}
