#include<iostream>
#include<algorithm>
using namespace std;

int a[11][3001];
int m,n,ans;

int count()
{
    int temp,sum = 0;
    for (int i = 0; i < n; i++)
    {
        temp = 0;
        for (int j = 0; j < m; j++)
        {
            if(a[j][i]) temp++;
        }
        if(temp*2 < m) temp = m - temp;
        sum += temp;
    }
    return sum;
}

void solve(int t)
{
    int j, tem;
    if(t < m) solve(t + 1);
    else
    {
        tem = count();
        if(tem > ans) ans = tem;
        return ;
    }
    if(ans == m * n) return ;
    for(j = 0; j < n; j++)
        a[t][j] = !a[t][j];
    if(t < m) solve(t + 1);
    else return ;
    if(ans == m * n) return ;
    for(j = 0; j< n; j++)
        a[t][j] = !a[t][j];
    return ;
}

int main()
{
    while (cin>>m)
    {
        cin>>n;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin>>a[i][j];
        ans = 0;
        solve(1);
        cout<<ans<<endl;
    }
}