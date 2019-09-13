 double getMax(vector<int> arr, int n) 
{ 
    int max = INT_MIN; 
    for (int i = 0; i < n; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
    return max; 
} 
int calculate(vector<int> C, int mid)
{
    int sum=0,no=1;
    for(int i=0;i<C.size();i++)
    {
        sum+=C[i];
        if(sum>mid)
        {
            sum=C[i];no++;
        }
    }
    return no;
}
int Solution::paint(int A, int B, vector<int> &C) {
    //sort(C.begin(),C.end());
    int len=C.size(), lo = getMax(C,len);
    int sum=0, hi;
    for(int i=0;i<len;i++)sum+=C[i];
    hi=sum;
    int no_painter;
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        no_painter=calculate(C,mid);
        if(no_painter<=A)
        {
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
    }
    return (int)((lo * (long long) B) % 10000003);
}
