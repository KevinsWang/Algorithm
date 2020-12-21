#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int r(double x)
{
    int ans = x;
    if(x - ans > 0.5) ans += 1;
    return ans;
}

int main()
{
    double a,b;
    while (cin>>a)
    {
        cin>>b;
        if(a == 0 || b == 0) cout<<0<<endl;
        else{
            double x = b/a/2.0;
            cout<<r(x)<<endl;
        }
    }
}
