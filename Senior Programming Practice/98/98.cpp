#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int find(string m, string x)
{
    int mlen = m.size(), xlen = x.size();
    int ans = 0, i, j, MAX = 0;
    for (i = 0; i < xlen; i++)
    {
        if(x.substr(i, mlen) == m)
        {
            i += mlen - 1;
            ans++;
        }
        else ans = 0;
        if(MAX < ans) MAX = ans;
    }
    return MAX;
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        string line;
        string str1 = "dongfangxu";
        string str2 = "zap";
        int M1 = 0, M2 = 0;
        cin>>line;
        M1 = find(str1, line);
        M2 = find(str2, line);
        if(M1 >= M2) cout<<"dongfangxu!"<<endl;
        else cout<<"zap!"<<endl;
    }
}
