vector<string> Solution::fullJustify(vector<string> &A, int B) {
    int n=A.size();
    vector<string> ans;
    int noChar=0, noSpace=0;
    int i=0, j;
    for(;i<n;)
    {
        noChar=0;noSpace=0;
        string temp="";
        for(j=i;j<n;j++)
        {
            if(noChar+noSpace+A[j].size()<=B)
            {
                noChar+=A[j].size();
                noSpace++;
            }
            else{
             break;
            }
            
        }
        noSpace--;
        if(j==n)
        {//cout<<B<<" "<<noSpace<<" "<<noChar<<endl;
            temp+=A[i];
            for(j=0;j<noSpace;j++)
            {
                
                temp+=string(1, ' ');
                temp+=A[i+j+1];
                //cout<<temp<<endl;
            }
            
            temp+=string(B - noSpace - noChar, ' ');

        }
        else if(noSpace==0)
        {
            temp+=A[i];
            temp+=string(B-noChar, ' ');
        }
        else
        {
            temp+=A[i];
            int noPadding=(B- noChar- noSpace)/noSpace;
            int remain=(B- noChar- noSpace)%noSpace;
            //if(remain--)temp+=string(1, ' ');
            for(j=0;j<noSpace;j++)
            {
                temp+=string(noPadding+1, ' ');
                if(remain)
                {
                    temp+=string(1, ' ');
                    remain--;
                }    
                temp+=A[i+j+1];
                //cout<<temp<<endl;
                
            }
        }
        //cout<<temp<<endl;
        ans.push_back(temp);
        i+=noSpace+1;//if(i>=n)exit(0);
        
    }
    return ans;
}
