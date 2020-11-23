#include<iostream>
#include<unordered_map>
using namespace std;

int a[100001], m[10001];   // 模拟出了一个hash表

int main()
{
    int N, t;
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>t;
        a[i] = t;
        m[t]++;
    }
    int ans = -1;
    for (int i = 0; i < N; i++)
    {
        if(m[a[i]] == 1) 
        {
            ans = a[i];
            break;
        }
    }
    if(ans != -1) printf("%d", ans);
    else printf("None");
    return 0;
}
