#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int t = 1; t <= T; t++)
    {
        int r,c;
        cin>>r>>c;
        int dp[r+1][c+1];
        int area[r+1][c+1];
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                scanf("%d", &area[i][j]);
        dp[1][1] = area[1][1];
        for (int i = 2; i <= r; i++) dp[i][1] = dp[i-1][1] + area[i][1];
        for (int i = 2; i <= c; i++) dp[1][i] = dp[1][i-1] + area[1][i];
        for (int i = 2; i <= r; i++)
        {
            for (int j = 2; j <= c; j++)
            {
                dp[i][j] = max(max(dp[i-1][j], dp[i-1][j-1]),dp[i][j-1]) + area[i][j];   
            }
        }
        printf("Case #%d: %d\n", t, dp[r][c]);
    }
    
}