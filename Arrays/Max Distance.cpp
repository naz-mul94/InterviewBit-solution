int Solution::maximumGap(const vector<int> &A) {
    if(A.size()==1)return 0;
        if(A.size()==0)return -1;
    vector<pair<int, int>> index;
    for(int i=0;i<A.size();i++)
    {
        index.push_back(make_pair(A[i],i));
    }
    sort(index.begin(),index.end());
    int max_distance=INT_MIN,max_index=index[A.size()-1].second;
    for(int i=A.size()-2;i>=0;i--)
    {
        max_distance=max(max_distance, max_index-index[i].second);
        max_index=max(max_index,index[i].second);
    }
    if(max_distance<0){return 0;}
    else return max_distance;
}
