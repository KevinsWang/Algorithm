#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int dp[101][101];
int main()
{
    // i: ball, j: box
    for (int i = 0; i < 101; i++)
        for (int j = 1; j < 101; j++)
        {
            if(i == 0 || j == 1) dp[i][j] = 1;
            else if(i < j) dp[i][j] = dp[i][i];
            else if(i >= j) dp[i][j] = dp[i][j-1] + dp[i-j][j];
        }
    int a,b;
    while (cin>>a)
    {
        cin>>b;
        cout<<dp[a][b]<<endl;
    }
}
