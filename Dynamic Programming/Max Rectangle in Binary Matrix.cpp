int ans;
void largestRectangleArea(vector<int>& arr)
{
   int max=0;
    stack<int> hist;
    int i=0;
    for(;i<arr.size();)
    {
        if(hist.empty()||arr[hist.top()]<=arr[i])
        {
            hist.push(i++);
        }
        else
        {
            int tp=arr[hist.top()];
            hist.pop();
            int area=tp*(hist.empty()?i:i-hist.top()-1);
            if(max<area)
            max=area;
        }
    }
    while(!hist.empty())
    {
        int tp=arr[hist.top()];
        hist.pop();
        int area=tp*(hist.empty()?i:i-hist.top()-1);
        if(max<area)
        max=area;
    }
    if(max>ans)
    ans=max;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
    if(A.size()==0)return 0;
    ans=0;
    int row=A.size();
    int col=A[0].size();
    vector<int> temp(col, 0);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(A[i][j]==0)
            temp[j]=0;
            else
            {
                temp[j]+=A[i][j];
            }
        }
        largestRectangleArea(temp);
    }
    return ans;
}
