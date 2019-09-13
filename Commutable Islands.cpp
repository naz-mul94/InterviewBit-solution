//using Kruskal algorithm
vector<pair<pair<int, int>, int>> cost;
vector<int> parent, r;
int vertex, edge;
bool sortCol(const pair<pair<int, int>, int>& x, const pair<pair<int, int>, int>& y)
{
    return (x.second<y.second);
}

int find_set(int u)
{
    int x=parent[u];
    if(x!=u)
        x=find_set(x);
    return x;
}

void merge(int u, int v)
{
    int x=find_set(u);
    int y=find_set(v);
    if(r[x]<r[y])
    parent[x]=y;
    else
    parent[y]=x;
    if(r[y]==r[x])
    r[x]++;
    
}
void createSet()
{
    for(int i=1;i<=vertex;i++)
    {
        parent[i]=i;
        r[i]=0;
    }
}

int kruskal()
{
    createSet();
    int minCost=0;
    for(int i=0;i<edge;i++)
    {
        int u=cost[i].first.first;
        int v=cost[i].first.second;
        if(find_set(u)!=find_set(v))
        {
            minCost+=cost[i].second;
            merge(u, v);
        }
    }
    return minCost;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    cost.clear();
    edge=B.size();
    vertex=A;
    r.resize(A+1);
    parent.resize(A+1);
    for(int i=0;i<edge;i++)
    {
       cost.push_back({{B[i][0], B[i][1]}, B[i][2]});
    }
    sort(cost.begin(), cost.end(), sortCol);
    return kruskal();
    
}
