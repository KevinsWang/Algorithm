#include<iostream>
#include<cmath>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

vector<string> line[2502];

int main()
{
    int M,K, t, x;
    string s;
    scanf("%d%d",&M,&K);
    while (M--)
    {
        cin>>s>>t;
        while (t--)
        {
            scanf("%d",&x);
            line[x].push_back(s);
        }
    }
    for (int i = 1; i <= K; i++)
    {
        printf("%d %d\n", i,  line[i].size());
        sort(line[i].begin(),line[i].end());
        for (auto j = line[i].begin(); j != line[i].end(); j++)
        {
            printf("%s\n", (*j).c_str());
        }
        
    }
}