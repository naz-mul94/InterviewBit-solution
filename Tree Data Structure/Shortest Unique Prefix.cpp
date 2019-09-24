struct trie
{
    struct trie* children[26];
    bool endOfWord;
    int frequency;
};
trie* getnode()
{
    trie* node=new trie;
    for(int i=0;i<26;i++)
    node->children[i]=NULL;
    node->endOfWord=false;
    node->frequency=0;
    return node;
}
void constructTrie(trie* root, string word)
{
    trie* temp=root;
    for(int i=0;i<word.size();i++)
    {
        char index=word[i]-'a';
        if(temp->children[index])
        {
            temp=temp->children[index];
            temp->frequency++;
        }
        else
        {
            trie* node=getnode();
            temp->children[index]=node;
            temp=temp->children[index];
            node->frequency++;
        }
    }
    temp->endOfWord=true;
}

void fetchAns(trie* root, string word, vector<string> &ans)
{
    string st="";
    trie* temp=root;
    for(int i=0;i<word.size();i++)
    {
        st+=word[i];
        int index=word[i]-'a';
        temp=temp->children[index];
        if(temp->frequency==1)break;
    }
    ans.push_back(st);
}
vector<string> Solution::prefix(vector<string> &A) {
    trie* root=getnode();
    vector<string> ans;
    for(int i=0;i<A.size();i++)
    {
        constructTrie(root, A[i]);
    }
    for(int i=0;i<A.size();i++)
    {
        fetchAns(root, A[i], ans);
    }
    return ans;
}
