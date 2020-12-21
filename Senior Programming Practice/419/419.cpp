#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
using namespace std;

// 此方法应该是超界了
// int card[102];
// int index__[100005];

// int main()
// {
//     int T;cin>>T;
//     int n,x;
//     int a[2]; // 0: xay, 1: amr
//     while (T--)
//     {
//         memset(card, 0, sizeof(card));
//         memset(index__, -1, sizeof(index__));
//         cin>>n;
//         a[0] = a[1] = 0;
//         for (int i = 0, j = 0; i < n; i++, j++)
//         {
//             cin>>x;
//             if(index__[x] == -1)
//             {
//                 index__[x] = j;
//                 card[j] = x;
//             }
//             else
//             {
//                 int temp = index__[x];
//                 a[i%2] += (j - temp + 1);
//                 for (int p = index__[x]; p < j; p++)
//                 {
//                     index__[card[p]] = -1;
//                     card[p] = 0;
//                 }
//                 j = temp - 1;
//             }
//         }
//         if(a[0] > a[1]) cout<<"xay"<<endl;
//         else cout<<"amr"<<endl;
//     }
// }

map<int, int> mp; // card, index
int a[2];
int card[105];
int main()
{
    int T;cin>>T;
    while (T--)
    {
        int n;
        cin>>n;
        mp.clear();
        memset(card, 0, sizeof(card));
        a[0] = a[1] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin>>card[i];
            if(mp[card[i]] > 0)
            {
                int count = 0;
                for(int j = mp[card[i]]; j <= i ; j++)
                {
                    if(card[j] > 0) count++;
                    mp[card[j]] = 0;
                    card[j] = 0;
                }
                a[i%2] += count;
            }
            else mp[card[i]] = i;
        }
        if(a[0] < a[1]) cout<<"xay"<<endl;
        else cout<<"amr"<<endl;
    }
    
}