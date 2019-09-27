int Solution::power(string A) {
     int n=A.size();
    if(n==0)return 0;
    if(A=="1")return 0;
    int i=0,j;

    while(A[i]=='0'&&i<n)
    i++;

    if(i==n)return 0;
    string newNum="";
    while(i<n)
    newNum+=A[i++];
    n=newNum.size();
    int Dividend=0;
    string result="";
    while(n!=1)
    {
        if((newNum[n-1]-'0')%2==1)return 0;
        for(i=0,j=0;i<n;i++)
        {
            Dividend=Dividend*10+newNum[i]-'0';
            if(Dividend<2&&i!=0)
            {
                result+='0';
                continue;
            }
            result+=Dividend/2+'0';
            Dividend=Dividend%2;
        }
        //cout<<result<<endl;
        i=0;
        while(result[i]=='0'&&i<result.size())
        i++;
        if(i==result.size())return 0;
        newNum="";
        while(i<n)
        newNum+=result[i++];//cout<<newNum<<endl;
        n=newNum.size();//cout<<n<<endl;
        result.clear();//cout<<result<<endl;cout<<"------------------\n";
    }
    if((newNum[0]-'0')%2==1)return 0;
    return 1;
    
}
