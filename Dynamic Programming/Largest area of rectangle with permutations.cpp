int Solution::solve(vector<vector<int> > &A) {
    int row=A.size();
    int col = A[0].size();
    int max=0;
    vector<vector<int>> conOne(row+1, vector<int>(col+1, 0));
    for(int j=1;j<=col;j++)
    {
        for(int i=1;i<=row;i++)
        {
            if(A[i-1][j-1]==0)
            conOne[i][j]=0;
            else
            {
                conOne[i][j]=1+conOne[i-1][j];
            }
        }
    }
    for(int i=1;i<=row;i++)
    {
        sort(conOne[i].begin()+1, conOne[i].end(), greater<int>());
    }
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(conOne[i][j]*j>max)
            max=conOne[i][j]*j;
        }
    }
    return max;
}
