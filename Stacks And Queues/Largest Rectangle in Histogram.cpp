int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> temp;
    int tp;
    int max_rect=INT_MIN,i;
    for( i=0;i<A.size();)
    {
        if(temp.empty()||A[temp.top()]<=A[i])
        {
            temp.push(i++);
        }
        else
        {
            tp=A[temp.top()];
            temp.pop();
            int area=tp*(temp.empty()?i:i-temp.top()-1);
            if(area>max_rect)
            max_rect=area;
        }
    }
    while(!temp.empty())
    {
        tp=A[temp.top()];
        temp.pop();
        int area=tp*(temp.empty()?i:i-temp.top()-1);
        if(area>max_rect)
        max_rect=area;
    }
    return max_rect;
}
