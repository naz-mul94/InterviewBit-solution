pair<int, int> max_r8(const vector<int> &A,int start, int end)
{
    pair<int, int> ans;
    ans.first=INT_MIN;
    for(int i=start;i<=end;i++)
    {
        if(ans.first<A[i])
        {
            ans.first=A[i];
            ans.second=i;
        }
    }
    return ans;
    
}

int Solution::trap(const vector<int> &A) {
    int n=A.size();
    pair<int, int> max=max_r8(A, 0, n-1) ;
    int i=0, j=1, water=0, left=A[0];
    for(j=1;j<n-1;j++)
    {
        if(j<max.second)
        {
            int min1=min(left, max.first);
            water+=((min1-A[j])>0)?(min1-A[j]):0;
            if(left<A[j])
            left=A[j];
        }
        else
        {
            max=max_r8(A,j+1,n-1);
            int min1=min(left, max.first);
            water+=((min1-A[j])>0)?(min1-A[j]):0;
            if(left<A[j])
            left=A[j];
        }
    }
    return water;
}
