#include<iostream>
#include<cmath>
#include<map>
#include<set>
using namespace std;

int N,K, t, x;
string name;
map<int, set<string>> line;

int main()
{
    cin>>N>>K;
    for (int i = 0; i < N; i++)
    {
        cin>>name>>t;
        while (t--)
        {
            scanf("%d",&x);
            line[x].insert(name);
        }
    
    }
    for (auto i = line.begin(); i != line.end(); i++)
    {
        printf("%d %d\n", i->first,i->second.size());
        for (auto j = i->second.begin(); j != i->second.end(); j++)
        {
            printf("%s\n", (*j).c_str());
        }
    }
    return 0;
}