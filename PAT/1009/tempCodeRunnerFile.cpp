#include<iostream>
#include <iomanip>
using namespace std;

struct poly
{
    int x;          //次数
    double y;       //系数
}Poly[20];

double ans[1005]={0};

int main()
{
    int m,n;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        cin>>Poly[i].x>>Poly[i].y;
    }
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a;
        double b;
        cin>>a>>b;
        for (int j = 0; j < m; j++)
        {
            ans[Poly[j].x + a] += Poly[j].y * b;
        }
    }
    int count = 0;
    for (int i = 1005 - 1; i > 0; i--)
    {
        if(ans[i] != 0) count++;
    }
    cout<<count;
    for (int i = 1005 - 1; i > 0; i--)
    {
        if(ans[i] != 0) cout<<" "<<i<<" "<<setiosflags(ios::fixed)<<setprecision(1)<<ans[i];
    }
}