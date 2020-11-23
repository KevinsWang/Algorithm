#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int m , a = 1;
    scanf("%d",&m);
    int left,right, ans = 0;
    while(m / a)
    {
        int now = m / a % 10;
        left = m / (a * 10);
        right = m % a;
        if(now == 0) ans += left*a;
        else if(now == 1) ans += left*a + 1 + right;
        else if(now > 1) ans += (left + 1) * a;
        a *= 10;
    }
    printf("%d", ans);
    return 0;
}