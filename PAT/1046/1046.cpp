#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int total = 0,N,M;
    int dis[100001], away[100001], flag[100001];
    cin>>N;
    for (int i = 1; i <= N; i++)
    {
        cin>>dis[i];
        total += dis[i];
        if( i < N )
        {
            away[i + 1] = total;
            flag[i + 1] = 1;
        }
    }
    away[1] = 0;
    flag[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        if(away[i] > total - away[i]) 
        {
            away[i] = total - away[i];
            flag[i] = 0;
        }
    }
    cin>>M;
    for (int i = 0; i < M; i++)
    {
        int a , b;
        cin>>a>>b;
        if(flag[a] ^ flag[b] == 0)
            printf("%d\n", abs(away[a] - away[b]));
        else printf("%d\n", min(away[a] + away[b], total - (away[a] + away[b])));
    }
    
}