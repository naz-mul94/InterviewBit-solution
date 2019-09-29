int ans;
vector<int> temp;
vector<int> temp1;
void lis(const vector<int> &A, int n)
{
    int res, max_ending=1;
    for(int i=1;i<n;i++)
    {
        for (int j=0;j<i; ++j)
        {
            if(A[j]<A[i]&&temp[i]<temp[j]+1)
                temp[i]=temp[j]+1;
        }

    }
}
void lds(const vector<int> &A, int n)
{
    for(int i=n-2;i>=0;i--)
    {
        for (int j=n-1;j>i; --j)
        {
            if(A[j]<A[i]&&temp1[i]<temp1[j]+1)
                temp1[i]=temp1[j]+1;
        }

    }
}
int Solution::longestSubsequenceLength(const vector<int> &A) {
    ans=0;
    if(A.size()==0)return 0;
    if(A.size()==1)return 1;
    temp.assign(A.size(), 1);
    temp1.assign(A.size(), 1);
    lis(A, A.size());
    lds(A, A.size());
    for(int i=0;i<A.size();i++)
    {
        if(ans<(temp[i]+temp1[i]-1))
        ans=temp[i]+temp1[i]-1;
    }
    
    return ans;
}
