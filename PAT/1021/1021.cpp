#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define N 10001
using namespace std;
 
vector<vector<int>> m;  //临接表
vector<int> path;       //存放同一深度的几个节点数
bool visit[N] = {false};
int max_depth = 0;
set<int> ans;
int n;

void dfs(int root, int deep)
{
    if(deep > max_depth)
    {
        max_depth = deep;
        path.clear();
        path.push_back(root);
    }
    else if(deep == max_depth) path.push_back(root);
    visit[root] = true;
    for (int i = 0; i < m[root].size(); i++)
        if(visit[m[root][i]] == false)
            dfs(m[root][i], deep + 1);
}


int main()
{
    scanf("%d", &n);
    m.resize(n + 1);        // 因为这是用两个vector嵌套出的邻接表所以需要事先对大小进行限定
    for (int i = 0; i < n - 1; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        m[a].push_back(b);
        m[b].push_back(a);
    }

    int k = 0,root;
    for (int i = 1; i <= n  ; i++)
    {
        if(visit[i] == false)
        {
            k++;
            dfs(i, 0);
            if( i == 1)
            {
                if(!path.empty())
                {
                    root = path[0];
                    for (int j = 0; j < path.size(); j++)
                        ans.insert(path[j]);
                }
            }
        }
    }

    if(k > 1) printf("Error: %d components", k);
    else
    {
        fill(visit, visit + N, false);  // 重新对dfs时，要将访问数组也初始化
        path.clear();
        dfs(root, 0);
        for (int i = 0; i < path.size(); i++)
            ans.insert(path[i]);
        for (auto i = ans.begin(); i != ans.end(); i++)
            printf("%d\n", *i);
    }
    return 0;
}
