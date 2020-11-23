/**
 * @file 1045.cpp
 * @author your name (you@domain.com)
 * @brief   将原数据进行转换，然后按照不下降最长子序列的方式来写
 * @version 0.1
 * @date 2020-09-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include<iostream>
#include<vector>

using namespace std;

int N,M,L;
int favorite[201], stripe[10001], dp[10001];
int num = 0, maxn = 0;
int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= M; i++)
    {
        int t;
        scanf("%d",&t);
        favorite[t] = i;
    }
    scanf("%d",&L); 
    for (int i = 0; i < L; i++)
    {
        int t;
        scanf("%d", &t);
        if(favorite[t] >= 1)
            stripe[num++] = favorite[t];        //将原数据转化为下标，于是构成不下降子序列的解题方法
    }
    for (int i = 0; i < num; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if(stripe[i] >= stripe[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxn = max(maxn, dp[i]);
    }
    printf("%d", maxn);
}