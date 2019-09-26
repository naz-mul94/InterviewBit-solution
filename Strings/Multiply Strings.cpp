string adjust(string x, int j)
{
    if(j==0)return x;
    for(int i=0;i<j;i++)
    {
        x=x+'0';
    }
    //cout<<x<<endl;
    return x;
}
string add(string x, string y)
{
    if(!x.compare("0"))return y;
    if(!y.compare("0"))return x;
    int n=x.size()-1, m=y.size()-1;
    int sum=0, carry=0,i;
    string temp;
    for(i=min(n, m);i>=0;i--)
    {
        int a=x[n]-'0';
        int b=y[m]-'0';
        sum=a+b+carry;
        carry=sum/10;
        sum=sum%10;
        temp=to_string(sum)+temp;
        n--;m--;
    }
    if(x.size()>y.size())
    {
        for(i=n;i>=0;i--)
        {
            int a=x[i]-'0';
            sum=a+carry;
            carry=sum/10;
            sum=sum%10;
            temp=to_string(sum)+temp;
        }
    }
    else if(x.size()<y.size())
    {
        for(i=m;i>=0;i--)
        {
            int a=y[i]-'0';
            sum=a+carry;
            carry=sum/10;
            sum=sum%10;
            temp=to_string(sum)+temp;
        }
    }
    //cout<<temp<<endl;
    if(carry!=0)
    temp=to_string(carry)+temp;
    //cout<<temp<<endl;
    return temp;
    
}
string prod(string A, char num)
{
    if(num=='0')return "0";
    if(num=='1')return A;
    string temp="";
    int sum=0, carry=0, y=num-'0';
    for(int i=A.size()-1;i>=0;i--)
    {
        int x=A[i]-'0';
        sum=x*y+carry;
        carry=(sum/10);
        sum=(sum>9?sum%10:sum);
        temp=to_string(sum)+temp;
    }
    if(carry!=0)temp=to_string(carry)+temp;
    //cout<<temp<<endl;
    return temp;
}
string Solution::multiply(string A, string B) {
    if(!A.compare("0")||!B.compare("0"))return "0";
    int j=0;
    string x="0", y="0";
    for(int i=B.size()-1;i>=0;i--)
    {
        y=prod(A, B[i]);//cout<<y<<endl;
        y=adjust(y, j);//cout<<y<<endl;
        x=add(x, y);//cout<<x<<endl;cout<<"------------------\n";
        j++;
    }
    int count=0;
    for(int i=0;i<x.size();i++)
    {
        if(x[i]=='0')count++;
        else break;
    }
    x.erase(0,count);
    return x;
}
