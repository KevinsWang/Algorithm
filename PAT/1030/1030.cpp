#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;

int N,M,S,D;
int e[502][502], weight[502][502], dis[502];
int minCost = inf;
bool visit[502] = {false};
vector<int> pre[502], path, tempath;

void dfs(int d)
{
    tempath.push_back(d);
    if(d == S)   //到达原点，计算cost
    {
        int cost = 0;
        for (int i = tempath.size() - 1; i > 0 ; i--)
        {
            cost += weight[tempath[i]][tempath[i-1]];
        }
        if(cost < minCost)
        {
            minCost = cost;
            path = tempath;
        }
        tempath.pop_back();
        return ; 
    }
    for (int i = 0; i < pre[d].size(); i++)
        dfs(pre[d][i]);
    tempath.pop_back();
}

int main()
{
    scanf("%d%d%d%d",&N,&M,&S,&D);
    fill(e[0], e[0] + 502*502, inf);
    fill(dis, dis + 502, inf);
    //graph.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a,b;
        scanf("%d%d", &a,&b);
        scanf("%d%d", &e[a][b],&weight[a][b]);
        //graph[a].push_back(b);
        //graph[b].push_back(a);
        e[b][a] = e[a][b];
        weight[b][a] = weight[a][b];
    }

    dis[S] = 0;                     // 设置原点
    for (int i = 0; i < N; i++)
    {
        int u = -1, minn = inf;
        for (int j = 0; j < N; j++) // 找到此时到原点的最短距离的点
        {
            if(visit[j] == false && dis[j] < minn)
            {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;            // 标记为已访问
        for (int v = 0; v < N; v++) // 将此点能够到达的点的最短距离都进行更新
        {
            if(visit[v] == false && e[u][v] != inf)
            {
                if(dis[v] > e[u][v] + dis[u])
                {
                    dis[v] = e[u][v] + dis[u];
                    pre[v].clear();         // 将最短距离时的前面一个点的下标进行保存
                    pre[v].push_back(u);
                }
                else if(dis[v] == e[u][v] + dis[u])
                    pre[v].push_back(u);
            }
        }
    }

    dfs(D);

    for (int i = path.size() - 1 ; i >= 0 ; i--)
    {
        printf("%d ", path[i]);
    }
    printf("%d %d", dis[D], minCost);
}