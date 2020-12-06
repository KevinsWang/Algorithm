#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename T>
T Max(T x, T y, T z)
{
	return x > y ? (x > z ? x : z) : (y > z ? y : z);
}

int main()
{
    int T,n,count,ans;
    cin>>T;
    count = 1;
    while (count <= T)
    {
        cin>>n; 
        int dp[n+1][n+1], board[n+1][n+1];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n ; j++)
                cin>>board[i][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n ; j++)
            {
                if(i == 1) dp[i][j] = board[i][j];
                else if(j == 1) dp[i][j] = board[i][j] + max(dp[i-1][j], dp[i-1][j+1]);
                else if(j == n) dp[i][j] = board[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
                else dp[i][j] = board[i][j] + Max(dp[i-1][j], dp[i-1][j+1], dp[i-1][j-1]);
            }
        ans = -1;
        for (int i = 1; i <= n; i++)
            if(dp[n][i] > ans) ans = dp[n][i];
        cout<<"Case "<<count<<":"<<endl;
        cout<<ans;
        count++;
        if(count <= T)
            cout<<endl<<endl;
    }
}
