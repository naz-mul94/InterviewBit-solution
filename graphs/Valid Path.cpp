int X[] = {0, 0, 1, 1, 1, -1, -1, -1};
int Y[] = {1, -1, 0, 1, -1, 0, 1, -1};
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<int>> rect(A+1, vector<int>(B+1, 0));
    int row=A, col=B;
    for(int i=0;i<=row;i++)
    {
        for(int j=0;j<=col;j++)
        {
            for(int k=0;k<C;k++)
            {
                if(sqrt(pow(E[k]-i, 2)+pow(F[k]-j, 2))<=D)
                {
                    rect[i][j]=1;break;
                }
                
            }
        }
    }
    if(rect[0][0]==1||rect[A][B]==1)return "NO";
    queue<pair<int, int>> point;
    point.push({0, 0});
    rect[0][0]=1;
    while(!point.empty())
    {
        int x=point.front().first;
        int y=point.front().second;
        point.pop();
        if(x==A&&y==B)return "YES";
        for(int i=0;i<8;i++)
        {
            int newX=x+X[i];
            int newY=y+Y[i];
            if(newX>=0&&newX<=A&&newY>=0&&newY<=B&&rect[newX][newY]==0)
            {
                point.push({newX, newY});
                rect[newX][newY]=1;
            }
        }
    }
    return "NO";
}
