#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N,M,K;
vector<int> graph[1002];
bool visit[1002];
int check_city, count;


void bfs(int nowVisit)
{
    queue<int> q;
    q.push(nowVisit);
    visit[nowVisit] = true;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int i = 0; i < graph[t].size(); i++)
        {
            if(visit[graph[t][i]] == false && graph[t][i] != check_city)
            {
                visit[graph[t][i]] = true;
                q.push(graph[t][i]);
            }
        }
    }
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
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < K; i++)
    {
        //cin>>check_city;
        scanf("%d", &check_city);
        fill(visit + 1, visit + N + 1, false);
        count = 0;
        for (int j = 1; j <= N; j++)
        {
            if(j == check_city) continue;
            if(!visit[j])
            {
                bfs(j);
                count++;
            }
        }
        cout<< count - 1<<endl;
    }

}