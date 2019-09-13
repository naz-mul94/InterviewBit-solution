int min_painter(vector<int> &C, long long int mid)
{
    int no=1;
    long long int sum=0;
    for(int i=0;i<C.size();i++)
    {
        sum+=C[i];
        if(sum>mid)
        {
            no++;
            sum=C[i];
        }
    }
    return no;
}
int Solution::paint(int A, int B, vector<int> &C) {
    long long int end=0, start=C[0];
    int n=C.size();
    for(int i=0;i<n;i++)
    {
        if(C[i]>start)
        start=C[i];
        end+=C[i];
    }
    long long int mid;
    while(start<end)
    {
        mid=start+(end-start)/2;
        if(A<min_painter(C, mid))
        start=mid+1;
        else
        end=mid;
        
    }
    return (start+end)/2*B%10000003;
}
