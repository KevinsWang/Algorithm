#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N,M,x,tmp;
    vector<int> line;
    cin>>N>>M;
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&x);
        if(x < M) line.push_back(x); 
    }
    sort(line.begin(),line.end());
    bool flag = false;
    auto i = line.begin();
    auto j = i + 1; 
    for (; *i <=  M / 2; i++)
    {
        for (j = i + 1; j != line.end() && *i + *j < M; j++);
        if(j != line.end() && (*i + *j) == M)
        {
            flag = true;
            break;
        }
    }
    
     
    if(flag) printf("%d %d", *i, *j);
    else printf("No Solution");
}