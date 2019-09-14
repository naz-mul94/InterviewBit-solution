int Solution::maximumGap(const vector<int> &A) {
    vector<pair<int,int>> num(A.size());
    for(int i=0;i<A.size();i++)
    {
        num[i].first=A[i];
        num[i].second=i;
    }
    sort(num.begin(), num.end());
    int ans=0;
    int min=num[0].second;
    for(int i=0;i<A.size()-1;i++)
    {
        if(num[i+1].second>min)
        {
            if(num[i+1].second-min>ans)
            ans=num[i+1].second-min;
        }
        else
        min=num[i+1].second;
        
    }
    return ans;
}
