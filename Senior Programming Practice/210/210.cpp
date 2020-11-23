#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string x , y;

int findLCS(string & str1, string & str2)
{
    int dp[10002][10002];
    if(str1.size() == 0 || str2.size() == 0) return 0;
    for (int i = 1; i <= str1.size(); i++)
        for (int j = 1; j <= str2.size(); j++)
        {
            if(str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    return dp[str1.size()][str2.size()];    
    
}

int main()
{
    int ans;
    while (cin >> x)
    {
        cin>>y;
        ans = findLCS(x, y);
        cout<<ans<<endl;
    }
}