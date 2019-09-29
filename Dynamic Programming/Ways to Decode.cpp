int Solution::numDecodings(string A) {
    int a=1, b=1;
    int count=0;
    
    if(A[0]=='0')return 0;if(A.size()==0||A.size()==1)return 1;
    for(int i=1;i<A.size();i++)
    {
        
        if(A[i]>'0')
        count=b;
        if(A[i-1]=='1'||(A[i-1]=='2'&&A[i]<'7'))
        {
            count+=a;
        }
        if(count==0)return 0;
        a=b;
        b=count;
        count=0;
    }
    return b;
}
