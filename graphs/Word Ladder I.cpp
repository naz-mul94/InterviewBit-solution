bool compare1(string A, string B)
{
    int count=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]!=B[i])count++;
        if (count > 1) return false; 
    } 
    return count == 1 ? true : false; 
}
void bfs(int &ans, string start, string end, vector<string> &dict)
{
    queue<pair<string, int>> que;
    que.push({start, 1});
    while(!que.empty())
    {
        string st=que.front().first;
        int len=que.front().second;
        que.pop();
        if(st.compare( end)==0)
        {
            if(len<ans)
            ans=len;
        }
        for(int i=0;i<dict.size();i++)
        {
            if(compare1(st, dict[i]))
            {
                que.push({dict[i], len+1});
                dict.erase(dict.begin()+i);
            }
        }
    }
    
}
int Solution::ladderLength(string start, string end, vector<string> &dictV) {
    //cout<<start<<"  "<<end<<"   "<<dictV.size()<<endl;
    //for(int i=0;i<dictV.size();i++)
    //cout<<dictV[i]<<endl;
    //if(compare(start, end)==0&&dictV.size()==0)return 1;
    if(compare(start, end)==0)return 1;
    int ans=INT_MAX;
    bfs(ans, start, end, dictV);
    if(ans==INT_MAX)
    return 0;
    return ans;
}
