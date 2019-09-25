int Solution::solve(string A, string B, vector<string> &C) {
    unordered_map<string, int> distance;
    unordered_set<string> dict(C.begin(), C.end());
    distance[A]=1;
    queue<string> que;
    que.push(A);
    while(!que.empty())
    {
        string temp=que.front();
        que.pop();
        if(temp.compare(B)==0)
        break;
        for(int i=0;i<temp.size();i++)
        {
            for(int j=0;j<26;j++)
            {
                string word=temp;
                word[i]=j+'a';
                if(dict.find(word)!=dict.end()&&distance.find(word)==distance.end())
                {
                    que.push(word);
                    distance[word]=distance[temp]+1;
                }
            }
            
        }
    }
    if(distance.find(B)==distance.end())return 0;
    return distance[B];
}
