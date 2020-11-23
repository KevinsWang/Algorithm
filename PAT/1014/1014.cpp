#include<bits/stdc++.h>
using namespace std;


int N,M,K,Q;
queue<int> q[25];
int t[1001];            //服务结束时间
int a[1001];            //服务时间
int ct[1001];           //剩余时间

int main()
{
    cin>>N>>M>>K>>Q;
    for (int i = 1; i <= K; i++)
    {
        cin>>a[i];
        ct[i] = a[i];
        t[i] = 99999;   //使用99999来表示一直都没服务到
    }

    int p = min(N*M, K);
    for (int i = 1; i <= p; i++)
    {
        int x = i % N;
        if(x == 0) x = N;
        q[x].push(i);   //将客户的ID压入各窗口的队列中
    }
    if(K>=N*M+1)
    {
        for (int i = N*M + 1; i <= K; i++)
        {
            q[N+1].push(i);     //将剩下的顾客都放入到一个等待队列中
        }
    }
    int T = 0;  // 当前计时的时刻，从0开始
    while(1)
    {
        int min_t = 99999;
        int flag = 1;   // 判断是否跳出循环的标志

        for (int i = 1; i <= N; i++)  // 遍历各个窗口的队列，找到最小的那个时刻值，同时也判断队列是否都为空了
        {
            if(!q[i].empty())
            {
                min_t = min(min_t, ct[q[i].front()]);      
                flag = 0;
            }
        }
        if(flag) break;
        T += min_t;
        for (int i = 1; i <= N; i++)
        {
            if(!q[i].empty())
            {
                ct[q[i].front()] -= min_t;
                if(ct[q[i].front()] == 0)  // 说明刚好已经服务完了
                {
                    t[q[i].front()] = T;
                    q[i].pop();
                    if(!q[N+1].empty())
                    {
                        q[i].push(q[N+1].front());
                        q[N+1].pop();
                    }
                }
            }
        }
        if(T >= 540)
        {
            for (int i = 1; i <= N; i++)
            {
                if(!q[i].empty())
                {
                    int x = q[i].front();
                    if(ct[x] != a[x])           // 当前剩余时间不等于服务时间时，仍要继续服务完
                    {
                        t[x] = T + ct[x];       
                    }
                }
            }
            break;
        }
    }
    for (int i = 0; i < Q; i++)
    {
        int x;
        cin >> x;
        int y = t[x];
        if(y == 99999) cout<<"Sorry"<<endl;
        else
        {
            int h = y / 60, m = y % 60;
            if(h < 2) cout<<"0";
            cout<< h + 8 << ":";
            if(m < 10) cout<<"0";
            cout<< m << endl;
        }
    }
    
}
