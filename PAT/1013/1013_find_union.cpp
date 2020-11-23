#include<iostream>
#include<set>
#include<vector>

using namespace std;

struct edge{
    int u,v;
    edge(int _u,int _v)
    {
        u = _u;
        v = _v;
    }
};

vector<edge> edges;
int N,M,K;
int check_city, count;
int father[1001];
set<int> fathers;

int find(int x)
{
    int a = x;
    while (x != father[x])
    {
        x = father[x];
    }
    while (a != father[a])
    {
        int z = a;
		a = father[a];
		father[z] = x;
    }
    return x;
}

void unions(int x, int y)
{
    int a = find(x);
    int b = find(y);
    if(a != b) father[a] = b;
}

int main()
{
    //cin>>N>>M>>K;
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; i++)
    {
        int a,b;
        // cin>>a>>b;
        scanf("%d %d",&a,&b);
        edges.push_back(edge(a,b));
    }
    for (int i = 0; i < K; i++)
    {
        //cin>>check_city;
        scanf("%d", &check_city);
        count = 0;
        fathers.clear();
        for (int j = 1; j <= N; j++)
        {
            father[j] = j;
        }
        for (int j = 0; j < edges.size(); j++)
        {
            if(edges[j].u == check_city || edges[j].v == check_city) continue;
            unions(edges[j].u, edges[j].v);
        }
        for (int j = 1; j <= N; j++)
        {
            if(j == check_city) continue;
            fathers.insert(find(j));
        }
        cout<< fathers.size() - 1 <<endl;
    }
    return 0;
}