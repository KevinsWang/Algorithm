#include<iostream>
using namespace std;

#define INF 0x3fffffff
#define maxn 500
int graph[maxn][maxn]={0};      //城市之间是否可到达
int city[maxn]={0};                 //每个城市中的医疗队数量
bool visit[maxn]={false};
int dis[maxn]={0};                  //源城市到每个城市的最小距离
int sum[maxn]={0};                  //源超市到每个城市的医疗队最大值
int same[maxn]={0};                 //从源城市到每个城市的最短路径数量

void Dij(int s, int d, int n)
{
    int cur = s,t,MIN,next;
    sum[s] = city[s];
    same[s] = 1; 
    while (1)
    {
        visit[cur] = true;
        MIN = INF;
        for (int i = 0; i < n; i++)
        {
            if(visit[i]) continue;
            if(graph[cur][i])
            {
                t = graph[cur][i]+dis[cur];
                if(t < dis[i] || dis[i] == 0)   // 出现更短的路径或者之前不可达
                {
                    dis[i] = t;
                    same[i] = same[cur];
                    sum[i] = sum[cur] + city[i];
                }
                else if(graph[cur][i]+dis[cur] == dis[i])
                {
                    same[i] += same[cur];
                    if(sum[i] < sum[cur] + city[i])
                        sum[i] = sum[cur] + city[i];                    
                }

            }
            if(dis[i] < MIN && dis[i] != 0)
            {
                next = i;
                MIN = dis[i];
            }
        }
        cur = next;
        if(cur == d) break;
    }
    return;

}

int main()
{
    int n,m,source,dest;
    cin>>n>>m>>source>>dest;
    for (int i = 0; i < n; i++)
    {
        cin>>city[i];
    }
    int x,y,z;
    for (int i = 0; i < m; i++)
    {
        cin>>x>>y>>z;
        graph[x][y] = z;
        graph[y][x] = z;
    }
    if(source == dest) // 起始相同时
    {
        cout<<1<<" "<<city[source];
        return 0;
    }
    Dij(source, dest, n);
    cout<<same[dest]<<" "<<sum[dest];
    return 0;
}