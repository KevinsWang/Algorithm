/*
杨辉三角的题，注意公式: 
    第n层（从0层开始）的值为  S(n): C(n,0)  C(n,1) ....  C(n,n-1) C(n,n)
这题可以利用这个结论
    S(n,k) = C(n,0) + C(n,1)*10^k + C(n,2)*10^2k + .... + C(n,n)*10^k
可以推出
    S(n,k) = (1 + 10^k)^n
然后再对m取模
    S(n,k) % m = (1 + 10^k)^n % m = [(1 + 10^k) % m]^n % m = [(1 % m + 10^k % m) % m]^n % m
此处可以使用快速幂取模即可
*/
#include <iostream>
#include <cmath>

using namespace std;
typedef long long LL;

LL pow_mod(int a, int b ,int mod)
{
    LL temp = a, res = 1;
    while (b)
    {
        /* code */
        if(b&1) res = res * temp % mod;
        temp = (temp * temp) % mod; 
        b >>= 1;
    }
    return res;
}

int main()
{
    int n, k , m, t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>m;
        LL ans = pow_mod(10, k , m);
        ans = (ans + 1) % m;
        cout<<pow_mod(ans, n, m)<<endl;
    }
}
/*
3
0 2 7
2 2 12345
5 2 1000000
*/