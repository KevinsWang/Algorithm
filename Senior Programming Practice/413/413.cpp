#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int T;cin>>T;
    int A,B,H;
    double ans;
    while (T-- )
    {
        cin>>A>>B>>H;
        ans = (double)B/A * H;
        printf("%.2f\n", ans);
    }
    
}
