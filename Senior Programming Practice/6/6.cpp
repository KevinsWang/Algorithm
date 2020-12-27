#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
int n,m,k;
struct node
{
    int p, h;
    node(int _p, int _h)
    {
        p = _p;
        h = _h;
    }
};  
int bfs(const vector<vector<int>> & line, int begin, int end)
{
    vector<bool> visit(n, false);
    queue<node> qu;
    qu.push(node(begin, 0));
    visit[begin] = true;
    while (!qu.empty())
    {
        node tmp = qu.front(); qu.pop();
        for (int i : line[tmp.p])
        {
            if(!visit[i])
            {
                if(i == end) return tmp.h;
                visit[i] = true;
                qu.push(node(i, tmp.h + 1));
            }
        }
    }
    return -1;
}
int main()
{
    cin>>n>>m;
    int x,y;
    vector<vector<int>> line(n);
    for (int i = 0; i < m; i++)
    {
        cin>>x>>y;
        line[x].push_back(y);
        line[y].push_back(x);
    }
    cin>>k;
    for (int j = 0; j < k; j++)
    {
        cin>>x>>y;
        if(x == y) cout<<0<<endl;
        else cout<<bfs(line, x, y)<<endl;
    }
}
