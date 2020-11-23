#include<iostream>
#include <iomanip>
using namespace std;
double a[1005];
int main()
{   
    int m,x,count = 0;
    double y;
    for(int i = 0; i < 2; i++)
    {
        cin>>m;
        for(int j = 0; j < m ; j++)
        {
            cin>>x>>y;
            a[x] += y;
        }
    }
    for(int i = 0; i < 1005; i++)
    {
        if(a[i] != 0) count++;
    }
    cout<<count;
    for(int i = 1004; i >= 0 ; i--)
    {
        if(a[i] != 0)
            cout<<" "<<i<<" "<<setiosflags(ios::fixed)<<setprecision(1)<<a[i];
    }
    return 0;
    
}