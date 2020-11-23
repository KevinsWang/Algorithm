#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int hashtable[1005];

int main()
{
    int M,N,x, i;
    bool flag = false;
    cin>>N>>M;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        hashtable[x]++;
    }
    for (i = 1; i <= M / 2; i++)
    {
        if(hashtable[i] && hashtable[M - i])
        {
            if(i == M - i && hashtable[i] <= 1) continue;       // 可能出现该数刚好时M一半的情况
            printf("%d %d", i, M - i);
            return 0;
        }
    }
    printf("No Solution");

}