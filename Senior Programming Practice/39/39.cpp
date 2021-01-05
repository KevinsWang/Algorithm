#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

const int MAX = 200005;
int father[MAX];
int value[MAX];
int cmax;


int findFather(int x)
{
    while (father[x] != x)
    {
        x = father[x];
    }
    return x;
}

void union_set(int x, int y)
{
    x = findFather(x);
    y = findFather(y);
    if(x == y) return;
    father[x] = y;
    if(y > cmax) cmax = y;
}

int main()
{
    int n, x;
    while (cin>>n && n)
    {
        cmax = 1;
        for (int i = 0; i < MAX; i++)
        {
            father[i] = i;
            value[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            cin>>x;
            father[x] = findFather(x);
            if(x == father[x])
            {
                value[x] = i;
                union_set(x, x + 1);
            }
            else
            {
                value[father[x]] = i;
                union_set(father[x], father[x] + 1);
            }
        }
        if(value[cmax] == 0) cmax--;
        cout<<cmax<<endl;
        for (int i = 1; i <= cmax; i++)
        {
            cout<<value[i];
            if(i < cmax) cout<<" ";
        }
        cout<<endl;
    }
    
}
