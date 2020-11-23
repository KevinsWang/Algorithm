#include<iostream>

using namespace std;
typedef long long ll;

ll fastPow(ll a, ll b, ll c)
{
    ll result = 1;
    while(b > 0)
    {
        if(b & 1) result = result * a % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return result;
}

int main()
{
    ll a,b,c;
    while (cin>>a)
    {
        if(a == 0) break;
        cin>>b>>c;
        cout<<fastPow(a,b,c)<<endl;
    }
    
}