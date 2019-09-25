string Solution::convert(string A, int B) {
    vector<string> temp(B);
    string ans="";
    int down=1;
    for(int i=0, j=0;i<A.size();i++)
    {
        temp[j]+=A[i];
        if(down&&j<B-1)
        {
            j++;
            if(j==B-1)down=0;
        }
        else if(!down&&j>0)
        {
            j--;
            if(j==0)down=1;
        }
    }
    for(int i=0;i<temp.size();i++)
    ans+=temp[i];
    return ans;
}
