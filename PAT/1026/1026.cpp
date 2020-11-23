#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define starttime 3600 * 8
#define endtime 3600 * 21
#define MAX 0x7FFFFFFF
struct customer
{
    int arrive;
    int progress;
    bool vip;
};


vector<customer> cst;

int table[102];  // 每台窗口的时间
int vt[102];
int cnt[102];

bool cmp(customer x, customer y)
{
    return x.arrive < y.arrive;
}

void printTime(int x)
{
    int hh, mm ,ss;
    hh = x / 3600;
    x %= 3600;
    mm = x /60;
    x %= 60;
    ss = x;
    printf("%02d:%02d:%02d", hh,mm,ss);
}

int main()
{
    int N;
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        int a,b,c,d;
        customer line;
        scanf("%d:%d:%d %d %d", &a, &b, &c, &d, &line.vip);
        line.arrive = a*3600 + b * 60 + c;
        if(d > 120) d = 120;                // 大于两小时的客人强制只能两个小时
        line.progress = d * 60;
        cst.push_back(line);
    }
    sort(cst.begin(), cst.end(), cmp);

    int K, M;
    cin>>K>>M;
    for (int i = 1; i <= K; i++)
    {
        table[i] = starttime;
    }
    
    while (M--)
    {
        int tmp;
        cin>>tmp;
        vt[tmp] = 1;
    }

    while (1)
    {
        int i,j;
        if(cst.empty()) break;      // 所有人都遍历完了，退出
        if(cst[0].arrive >= endtime) break;
        int minservetime = MAX;
        int mintabno = 0;
        for (i = 1; i <= K; i++)
        {
            if(table[i] < minservetime)
            {
                minservetime = table[i];
                mintabno = i; 
            }
        }
        if(minservetime >= endtime) break;      // 大于结束时间跳出
        int p = 0;
        bool flag = false;
        if(vt[mintabno] == 0)  // 非vip桌
        {
            if(cst[0].vip == 1) // 此时是vip客户，查找后面有没有vip桌子
            {
                // for (int m = 1; m <= K; m++)
                //     if(vt[m] == 1 && table[m] <= cst[0].arrive)
                //     {
                //         mintabno = m;
                //         minservetime = table[m];
                //         break;
                //     }
                int vipIndex = -1, minVipEnd = MAX;
                for (int m = 1; m <= K; m++)
                {
                    if(vt[m] == 1 && minVipEnd > table[m])
                    {
                        vipIndex = m;
                        minVipEnd = table[m];
                    }
                }
                if(vipIndex != -1 && minVipEnd <= cst[0].arrive)
                {
                    mintabno = vipIndex;
                    minservetime = minVipEnd;
                }
            }
        }
        else    // vip桌
        {
            int t;   
            for (t = 0; t < cst.size() && cst[t].arrive <= minservetime ; t++)
                if(cst[t].vip == 1)
                {
                    flag = true;
                    break;
                }
            if(flag == true) p = t;  
        }
        if(minservetime >= endtime) break;      // 大于结束时间跳出
        printTime(cst[p].arrive);
        int servtime = max(minservetime, cst[p].arrive);
        if(servtime < endtime) cnt[mintabno]++;
        printf(" ");
        printTime(servtime);        
        printf(" ");
        int waittime = ((servtime - cst[p].arrive) / 60) + ((servtime - cst[p].arrive) % 60 >= 30 ? 1 : 0);
        printf("%d\n",waittime);
        table[mintabno] = servtime + cst[p].progress;
        cst.erase(cst.begin() + p);
    }
    printf("%d", cnt[1]);
    for (int i = 2; i <= K; i++)
        printf(" %d", cnt[i]);
    
}