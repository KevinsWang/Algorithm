#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include <climits>

#define starttime 3600 * 8
#define endtime 3600 * 17
#define MAX 0x7FFFFFFF
using namespace std;

struct m
{
    int arrive;
    int process;
};


m line[10010];          // 所有顾客
int window[110];        // 窗口

bool cmp(m p1, m p2)
{
    return p1.arrive < p2.arrive;
}

int N,K;
int sumwait = 0;


int main()
{
    cin>>N>>K;
    for (int i = 0; i < N; i++)
    {
        string t;
        cin>>t>>line[i].process;
        if(line[i].process > 60)
        {
            line[i].process = 60;
        }
        line[i].arrive = ((t[0]-'0')*10 + (t[1]-'0'))*3600 + ((t[3]-'0')*10 + (t[4]-'0')) * 60 + 
            (t[6]-'0') * 10 + (t[7]-'0');
    }
    sort(line, line+N, cmp);

    for (int i = 0; i < K; i++)
    {
        window[i] = starttime;
    }
    
    int c=0;
    for (int i = 0; i < N; i++)
    {
        if (line[i].arrive > endtime) break;
        else
        {
            c++;
            int minservetime = MAX;
            int minwinno = 0;
            for (int j = 0; j < K; j++)
            {
                if(window[j] < minservetime)
                {
                    minservetime = window[j];
                    minwinno = j;
                }
            }
            int servtime = max(minservetime, line[i].arrive);
            sumwait += (servtime - line[i].arrive);
            window[minwinno] = servtime + line[i].process * 60;
        }
        
        
    }
    printf("%.1f\n", sumwait / 60.0 / c);

    return 0;
}