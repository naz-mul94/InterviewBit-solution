int R[]={-2, -2, 2, 2, -1, 1, 1, -1};
int CO[]={1, -1, 1, -1, 2, 2, -2, -2};
void bfs(int &ans, int A, int B, int C, int D, int E, int F, int move)
{
    
    queue<pair<pair<int, int>, int>> pos;
    pos.push({{C,D},move});
    map<pair<int,int>, int> mark;
    
    while(!pos.empty())
    {
        int r=pos.front().first.first;
        int c=pos.front().first.second;
        int m=pos.front().second;
        pos.pop();
        
        if(mark.find({r, c})!=mark.end())
        continue;
        else
        mark[{r, c}]=1;
        if(r==E&&c==F)
        {
            if(m<ans)
            ans=m;
        }
        for(int i=0;i<8;i++)
        {
            int newR =r+R[i];
            int newC=c+CO[i];
            if(newR>=1&&newR<=A&&newC>=1&&newC<=B)
            {
                pos.push({{newR, newC}, m+1});
            }
        }
    }
    
}
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int ans=INT_MAX;
    bfs(ans, A, B, C, D, E, F , 0);
    if(ans!=INT_MAX)
    return ans;
    else return -1;
}
