vector<string> Solution::prettyJSON(string A) {
    int n=A.size(), i=0, indentation=0;
    bool flag=false;
    vector<string> ans;
    for(;i<n;)
    {//cout<<i<<endl;if(i==100)return ans;
        string temp="";
        for(int j=0;j<indentation;j++)
        temp+='\t';
        flag=false;
        for(int j=i;j<n;j++)
        {
            if(A[j]=='{'||A[j]=='[')
            {
                if(flag)
                ans.push_back(temp);
                temp="";
                for(int k=0;k<indentation;k++)
                temp+='\t';
                temp+=A[j];
                ans.push_back(temp);
                indentation++;
                i=j+1;
                break;
            }
            else if(A[j]=='}'||A[j]==']')
            {
                if(flag)
                ans.push_back(temp);
                temp="";
                indentation--;
                for(int k=0;k<indentation;k++)
                temp+='\t';
                temp+=A[j];
                if(j+1<n&&A[j+1]==',')
                temp+=A[++j];
                ans.push_back(temp);
                i=j+1;
                break;
                
            }
            temp+=A[j];
            flag=true;
            i=j+1;
            if(A[j]==',')
            {
                ans.push_back(temp);
                break;
            }
        }
        
    }
    return ans;
}
