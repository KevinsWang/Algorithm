#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

struct TNode
{
    int v;
    int d;
};

int n, dis[50001], T, Tp;
vector<TNode> tree[50001];
TNode t1, t2;
int totallen, root, midroot, maxlen; 

int BFS(int begin)
{
    for (int i = 0; i <= n; i++) dis[i] = 0;       // 每个点到begin点的距离
    int visit[n + 3];
    memset(visit, 0 ,sizeof(visit));
    queue<int> qu;
    qu.push(begin);
    visit[begin] = 1;
    while (!qu.empty())
    {
        int tmp = qu.front();
        qu.pop();
        if(dis[tmp] > maxlen)
        {
            maxlen = dis[tmp];
            begin = tmp;
        }
        for (int i = 0; i < tree[tmp].size(); i++)
        {
            TNode t3 = tree[tmp][i];
            if(visit[t3.v] == 0)
            {
                visit[t3.v] = 1;
                dis[t3.v] = dis[tmp] + t3.d;
                qu.push(t3.v);
            } 
        }
    }
    return begin;

}

int main()
{
    cin>>T;
    Tp = T;
    while (T--)
    {
        if(Tp != T + 1) cout<<endl;
        cin>>n;
        totallen = 0;
        for (int i = 0; i <= n; i++)
            tree[i].clear();
        
        for (int i = 1; i < n; i++)
        {
            int x,y,d;
            cin>>x>>y>>d;
            t1.v = y; t1.d = d;
            t2.v = x; t2.d = d;
            tree[x].push_back(t1);
            tree[y].push_back(t2);
            totallen = totallen + d * 2;
        }
        maxlen = 0;
        midroot = BFS(1);
        maxlen = 0;
        BFS(midroot);

        cout<<"Case "<<Tp - T<<":\n"<<totallen - maxlen<<endl;
    }
    
}