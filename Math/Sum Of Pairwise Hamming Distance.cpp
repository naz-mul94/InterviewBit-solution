int Solution::hammingDistance(const vector<int> &A) {
    long long int sum=0;
    for(int i=0;i<32;i++)
    {
        int andmask, count=0;
        andmask=1<<i;
        for(int j=0;j<A.size();j++)
        {
            if((A[j]&andmask)!=0)count++;
            
        }
        sum+=(2*(count%1000000007)*((A.size()-count)%1000000007))%1000000007;
    }
    return sum%1000000007;
}
