#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int n = s.size(), res = 1;
    vector<vector<bool>> dp(n, vector<bool>(n, false));     // 生成一个n×n的判定矩阵
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
        if(i <= n - 2 && s[i] == s[i+1])
        {
            dp[i][i + 1] = true;
            res = 2;        // 至少为2了
        }
    }
    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            if(s[i] == s[j] && dp[i+1][j-1])
            {
                dp[i][j] = true;
                res = len;
            }
        }
    }
    printf("%d", res);
    return 0;
}