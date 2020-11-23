#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

const int inf = 0x3f3f3f3f;

using namespace std;

int cmax, n, sp, m;                //最大数量，站点数，终点编号，边数
int minNeed = inf, minBack = inf;
int e[510][510], dis[510], weight[510];
bool visit[510];

vector<int> pre[510], path, temppath;
/**
 * @brief 模拟各个路径的情况，得到最合适的结果，用前面得到的pre进行深度优先
 * 
 * @param v 
 */

void dfs(int v)
{
    temppath.push_back(v);
    if(v == 0)
    {
        int need = 0, back = 0;
        for (int i = temppath.size() - 1; i >= 0 ; i--)
        {
            int id = temppath[i];
            if(weight[id] > 0)
            {
                back += weight[id];    
            }
            else // 只有从原点出发时才会进行调整，返回时不会调整，所以need和back不是互补的关系
            {
                if(back > (0 - weight[id])) back += weight[id];
                else 
                {
                    need += ((0 - weight[id]) - back);
                    back = 0;
                }
            }
            
        }
        if(need < minNeed){
            minNeed = need;
            minBack = back;
            path = temppath;
        }
        else if(need == minNeed && back < minBack){
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();
        return ; 
    }
    for (int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    temppath.pop_back();
}

int main()
{
    fill(e[0], e[0] + 510*510, inf);
    fill(dis, dis + 510, inf);
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    for (int i = 1; i <= n ; i++)
    {
        scanf("%d", &weight[i]);
        weight[i] = weight[i] - cmax / 2;
    }
    for (int i = 0; i < m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        scanf("%d", &e[a][b]);
        e[b][a] = e[a][b];
    }
    /**
     * @brief dijkstra 将各个点到原点的最短路径找出，同时用pre来记录上一个点的下标
     * 
     */
    dis[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        int u = -1, minn = inf;
        for (int j = 0; j <= n; j++)
        {
            if(visit[j] == false && dis[j] < minn)
            {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for (int v = 0; v <= n; v++)
        {
            if(visit[v] == false && e[u][v] != inf)
            {
                if(dis[v] > dis[u] + e[u][v])
                {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(dis[v] == dis[u] + e[u][v])  // 有相同的最短路径时将各个都存入其中
                {
                    pre[v].push_back(u);
                }
            }
        }       
    }

    dfs(sp);
    printf("%d 0", minNeed);
    for (int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minBack);
    return 0;
}