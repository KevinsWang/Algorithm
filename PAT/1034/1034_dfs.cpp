#include <iostream>
#include <string.h>
#include <map>
#include <vector>
using namespace std;


string head;
int cnt, total;
map<string, int> weight;
map<string, bool> visit;
map<string, vector<string>> adjlist;
map<string, int> res;

void DFS(string start)
{
    visit[start] = 1;
    cnt++;
    total += weight[start];
    if(weight[start] > weight[head]) head = start;
    vector<string>::iterator it = adjlist[start].begin();

    for(;it != adjlist[start].end();it++)
    {
        if(visit[*it] == 0)
        {
            DFS(*it);
        }
    }
}

int main()
{
    int N,K,T,i = 0;
    cin>>N>>K;
    string m1, m2;
    while (i<N)
    {
        cin>>m1>>m2>>T;
        weight[m1] += T;
        weight[m2] += T;
        adjlist[m1].push_back(m2);
        adjlist[m2].push_back(m1);
        visit[m1] = 0;
        visit[m2] = 0;
        i++;
    }
    map<string, bool>::iterator ite = visit.begin();
    for(;ite != visit.end(); ite++)
    {
        if(ite->second == 0)
        {
            total = 0;
            cnt = 0;
            head = ite->first;
            DFS(ite->first);
        }
        if(cnt>2 && total / 2 > K) res[head] = cnt;
    }
    map<string, int>::iterator it = res.begin();
    cout<<res.size()<<endl;
    for(;it!=res.end();it++) cout<<it->first<<" "<<it->second<<endl;
    return 0;
}