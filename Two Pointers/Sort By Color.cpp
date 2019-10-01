void Solution::sortColors(vector<int> &A) {
    int red=0, white=0, blue=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==0)red++;
        else if(A[i]==1)white++;
        else blue++;
    }
    for(int i=0;i<A.size();i++)
    {
        if(red>0)
        {
            A[i]=0;red--;
        }    
        else if(white>0)
        {
            A[i]=1;
            white--;
        }    
        else A[i]=2;
    }
}
