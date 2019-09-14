#include<list>
int Solution::isValid(string A) {
    list<char> open_paren;
    stack<char> paren;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='('||A[i]=='{'||A[i]=='[')
        {
            paren.push(A[i]);
            open_paren.push_back(A[i]);
        }
        else if(A[i]==')'||A[i]=='}'||A[i]==']')
        {
            char c;
            if(A[i]==')')
            c='(';
            else if(A[i]=='}')
            c='{';
            else
            c='[';
            if(open_paren.back()==c)
            {
                open_paren.pop_back();
                paren.pop();
            }
            else return 0;
        }
    }
    if(paren.empty())return 1;
    return 0;
}
