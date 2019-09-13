/*
I am doing it using kruskal algo
I am takink rank is how many children, the parent has.
I m implementing path compression, otherwise you will get TLE.
*/
vector<int> parent, rank1;
int ans;
bool compare(vector<int> a, vector<int> b)
{
    int x=a[2];
    int y=b[2];
    return (x<y);
}
int find_set(int u)
{
    int x=parent[u];
    if(x!=u)
    {
        parent[u]=find_set(x);
    }
    return parent[u];
}

void merge(int u, int v)
{
    int parent_u=find_set(u);
    int parent_v=find_set(v);
    int rank_u=rank1[parent_u];
    int rank_v=rank1[parent_v];
    if(rank_u<rank_v)
    {
        parent[parent_u]=parent_v;
        rank1[parent_v]+=rank_u+1;
    }
    else
    {
        parent[parent_v]=parent_u;
        rank1[parent_u]+=rank_v+1;
    }
    
}
int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(), B.end(),compare);
    parent.resize(A+1);
    rank1.resize(A+1, -1);
    int n=B.size();
    ans=0;
    for(int i=1;i<=A;i++)
    {
        parent[i]=i;
        rank1[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        int u=B[i][0];
        int v=B[i][1];
        if(find_set(u)!=find_set(v))
        {
            ans+=B[i][2];
            merge(u, v);
        }
    }
    return ans;
}
