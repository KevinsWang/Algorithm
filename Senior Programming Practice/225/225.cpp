#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

bool visit[100005];
struct node
{
    int data;
    int minute;
    node(int _d, int _m)
    {
        data = _d;
        minute = _m;
    }
};

int main()
{
    int x , y;
    while (cin>>x)
    {
        cin>>y;
        if(x==y) {cout<<0<<endl ;continue;} 
        memset(visit, 0 , sizeof(visit));
        queue<node> qu;
        qu.push(node(x,0));
        visit[x] = 1;
        while (!qu.empty())
        {
            node tmp = qu.front();
            qu.pop();
            if(tmp.data - 1 ==  y || tmp.data + 1 == y || tmp.data * 2 == y)
            {
                cout<<tmp.minute + 1<<endl;
                break;
            }
            if(tmp.data - 1 >= 0 && visit[tmp.data - 1] == 0) 
            {
                qu.push(node(tmp.data - 1, tmp.minute + 1));
                visit[tmp.data - 1] = 1;
            }
            if(tmp.data + 1 <= 100000 && visit[tmp.data + 1] == 0)
            {
                qu.push(node(tmp.data + 1, tmp.minute + 1));
                visit[tmp.data + 1] = 1;
            }
            if(tmp.data * 2 <= 100000 && visit[tmp.data * 2] == 0)
            {
                visit[tmp.data * 2] = 1;
                qu.push(node(tmp.data * 2, tmp.minute + 1));
            }
        }
    }
        
}
