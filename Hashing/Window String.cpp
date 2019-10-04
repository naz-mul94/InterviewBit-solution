string Solution::minWindow(string A, string B) {
    int len=INT_MAX-1,c=0, st=0, end=0, min_st=-1,  flag=0;
    map<char, int> T, S;
    if(A.size()<B.size())return "";
    for(int i=0;i<B.size();i++)
    {
        if(T.find(B[i])==T.end())
        T[B[i]]=1;
        else
        T[B[i]]++;
    }
    //temp=T;
    for(int i=0;i<A.size();i++, end++)
    {
        if(T.find(A[i])!=T.end())
        {
            
            if(S.find(A[i])==S.end())
            S[A[i]]=1;
            else S[A[i]]++;
            if(S[A[i]]!=0&&S[A[i]]<=T[A[i]])
            c++;
            if(c==B.size())
            {
                while(T.find(A[st])==T.end()||(T.find(A[st])!=T.end()&&S[A[st]]>T[A[st]]))
                {
                    if((T.find(A[st])!=T.end()&&S[A[st]]>T[A[st]]))
                    S[A[st]]--;
                    st++;
                    
                }
                
                if(len>(end-st+1))
                {
                    len=end-st+1;
                    min_st=st;
                }
            }
        }
    }
    
    if(min_st==-1)return "";
    return A.substr(min_st,len);
    
}
