#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<cstring>
using namespace std;

int main()
{
    string a,b;
    while(cin>>a)
    {
        cin>>b;
        int visit[b.size()];
        memset(visit, 0, sizeof(visit));
        set<char> ans;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                if(a[i] == b[j] && visit[j] == 0)
                {
                    ans.insert(b[j]);
                    visit[j] = 0;
                    break;
                }
            }
        }
        for (auto c : ans) cout<<c;
        cout<<endl;
    }
}
