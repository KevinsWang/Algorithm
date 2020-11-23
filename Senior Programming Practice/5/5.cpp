#include<iostream>

using namespace std;

struct Goods
{
    int size;       // 大小
    int point;      // 价值
};

int bag(int n, Goods goods[], int v)
{
    int dp[n + 1][v + 1];
    for (int i = 0; i <= n; i++) dp[i][0] = 0;      // 初始化第一列
    for (int i = 0; i <= v; i++) dp[0][i] = 0;      // 初始化第一行

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if(j < goods[i - 1].size) dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j - goods[i - 1].size] + goods[i - 1].point, dp[i - 1][j]);
        }
    }
    return dp[n][v];
}

int main()
{
    int n,v,s,p;

    while (cin >> n)
    {
        Goods goods[n];
        
        for (int i = 0; i < n; i++)
        {
            cin>>goods[i].size>>goods[i].point;
        }
        cin>>v;
        cout<<bag(n, goods, v)<<endl; 
    }
    
}