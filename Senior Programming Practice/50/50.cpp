#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

struct edge
{
    int m,n;    // two points
    int w;      // weight
};

bool cmp(edge x, edge y)
{
    return x.w < y.w;
}

int find(int x, int visit[])
{
    while (visit[x] != x)
        x = visit[x];
    return x;
}

int main()
{
    int T, n, weight;
    cin>>T;
    while (T--)
    {
        cin>>n;
        vector<edge> line;
        int visit[n];
        for (int i = 0; i < n; i++) visit[i] = i;       // 所有都是自己的一类
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin>>weight;
                if(j > i)
                {
                    edge t;
                    t.m = i;
                    t.n = j;
                    t.w = weight;
                    line.push_back(t);
                }
            }
        }
        sort(line.begin(), line.end(), cmp);
        for (int i = 0; i < line.size(); i++)
        {
            int x = find(line[i].m, visit);
            int y = find(line[i].n, visit);
            if(x != y)
            {
                ans += line[i].w;
                visit[y] = x;
            }
        }
        cout<<ans<<endl;
    }
    
}
