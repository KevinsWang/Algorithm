#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> bonus, coupon;
int b1,b0, c1,c0;
int ans = 0;
int main()
{
    int N,t;
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>t;
        if(t > 0) c1++;
        coupon.push_back(t);
    }
    c0 = N - c1;
    sort(coupon.begin(), coupon.end());
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>t;
        if(t > 0) b1++;
        bonus.push_back(t);
    }
    b0 = N - b1;
    sort(bonus.begin(), bonus.end());
    vector<int>::iterator itc, itb;
    itc = coupon.end() - 1;
    itb = bonus.end() - 1;
    while (c1 > 0 && b1 > 0)
    {
        ans += *itc * *itb;
        c1--;b1--;itc--;itb--;
    }
    itc = coupon.begin();
    itb = bonus.begin();
    while (c0 > 0 && b0 > 0)
    {
        ans += *itc * *itb;
        c0--;b0--;itc++;itb++;
    }
    cout<<ans<<endl;
}   
