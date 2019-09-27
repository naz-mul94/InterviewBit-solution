string Solution::countAndSay(int A) {
    string seq="1";
    for(int i=2;i<=A;i++)
    {
        string temp="";
        char x=seq[0];
        int count=1; 
        for(int j=1;j<seq.size();j++)
        {
            if(x==seq[j])
            count++;
            else
            {
                temp+=to_string(count)+x;
                x=seq[j];
                count=1;
            }
        }
        temp+=to_string(count)+x;
        seq=temp;
        
    }
    return seq;
}
