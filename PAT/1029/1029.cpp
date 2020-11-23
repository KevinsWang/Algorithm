#include<iostream>
#include<vector>

using namespace std;

vector<int> s1, s2;


// int main()
// {
//     int N, m, t;
//     cin>>N;
//     for (int i = 0; i < N; i++)
//     {
//         cin>>t;
//         s1.push_back(t);
//     }
//     m = N;
//     cin>>N;
//     for (int i = 0; i < N; i++)
//     {
//         cin>>t;
//         s2.push_back(t);
//     }
//     m = (m + N + 1) / 2;
//     auto x1 = s1.begin();
//     auto x2 = s2.begin();
//     int ans, cnt = 0;
//     while(x1 != s1.end() && x2 != s2.end() && cnt < m)
//     {
//         if(*x1 < *x2)
//         {
//             ans = *x1;
//             x1++;
//             cnt++;
            
//         }
//         else
//         {
//             ans = *x2;
//             x2++;
//             cnt++;
//         }
        
//     }
//     if(cnt<m)
//     {
//         while (x1 != s1.end() && cnt < m)
//         {
//             ans = *x1;
//             x1++;
//             cnt++;
            
//         }
//         while (x2 != s2.end() && cnt < m)
//         {
//             ans = *x2;
//             x2++;
//             cnt++;
            
//         }
//     }
//     cout<<ans<<endl;
// }

int main()
{
    int N, m, t;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &t);
        s1.push_back(t);
    }
    m = N;
    scanf("%d", &N);
    m = (m + N + 1) / 2;
    auto x1 = s1.begin();
    int ans, cnt = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &t);
        while (x1 != s1.end() && cnt < m && *x1<t)
        {
            ans = *x1;
            x1++;
            cnt++;
        }
        if(cnt == m) break;
        ans = t;
        cnt++;
        if(cnt == m) break;
    }
    if(cnt < m)
    {
        while(cnt < m)
        {
            ans = *x1;
            x1++;
            cnt++;       
        }
    }
    printf("%d\n", ans);
}