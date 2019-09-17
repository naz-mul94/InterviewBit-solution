void parenthesis(vector<string> &ans, string temp, int o, int c, int A)
{
    if(o==c&&o==A)
    {
        ans.push_back(temp);
        return;
    }
    else if(o>A||c>A)
    return;
    if(o<A)
    {
        temp+="(";
        parenthesis(ans, temp, o+1, c, A);
        temp.pop_back();
    }
    if(c<o)
    {
        temp+=")";
        parenthesis(ans, temp, o, c+1, A);
        temp.pop_back();
    }
}
vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    string temp="";
    parenthesis(ans, temp, 0, 0, A);
}
