#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#define _MIN_ 0x80000000;
#define MOD 2006;
typedef long long LL;
using namespace std;

int pow_mod(int maxn, int N)
{
    int ans = maxn % MOD;
    int a = 2;
    while (N)
    {
        if(N % 2) ans *= a;
        a = (a * a) % MOD;
        N /= 2;
        ans %= MOD;
    }
    return ans;   
}

int main()
{
    int n;
    while (cin>>n && n)
    {
        int maxn = _MIN_;
        int x;
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            if(x > maxn) maxn = x;
        }
        while (maxn < 0)
        {
            maxn += 2006;
        }
        cout<<pow_mod(maxn, n - 1)<<endl;
    }
}
