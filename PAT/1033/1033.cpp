#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct st
{
    double price;
    double pos;
};

// 可能出现距离相同的情况
bool cmp(st x, st y)
{
    if(x.pos < y.pos) return true;
    else if(x.pos == y.pos) return x.price < y.price;
    else return false;
}

st line[501];
int cmax,D,avg,N;
int main()
{
    double tank = 0, cost = 0;      // 容量和花费
    int min, now;               // 起指针的作用
    
    cin>>cmax>>D>>avg>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>line[i].price>>line[i].pos;
    }
    line[N].pos = D;
	line[N].price = 0;
    sort(line, line + N + 1, cmp);
    if(line[0].pos != 0) 
    {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    now = 0;
    while (now < N)
    {
        // 无法到达紧挨着的下一个位置时
        if(line[now].pos + cmax * avg < line[now + 1].pos)
        {
            printf("The maximum travel distance = %.2f\n", line[now].pos + cmax * avg);
            break;
        }
        min = now;
        // 找到范围内的最小油价
        for (int i = now + 1; i <= N; i++)
        {
            if(line[i].pos > line[now].pos + cmax * avg) break;
            if(line[i].price <=  line[min].price)
            // 出现相等价格时要去更近的站，因为此次油价是由当前决定的，越远越贵
            {
                min = i;
                break;
            }
        }
        if(min == now)
        {   // 需要找到范围内第二小的油价
            min = now + 1;
            for (int i = min + 1; i <= N; i++)
            {
                if(line[i].pos > line[now].pos + cmax * avg) break;
                if(line[i].price <= line[min].price)
                    min = i;
            }
            // 将油加满
            cost += (cmax - tank) * line[now].price;
            // 到达该点后剩余的油量
            tank = cmax - (line[min].pos - line[now].pos) / avg;
        }
        // 找到了最小油价，将油加到刚好到达的量
        else    
        {   
            cost += ((line[min].pos - line[now].pos) / avg - tank) * line[now].price;
            tank = 0;
        }
        now = min;
    }
    if(now == N)
    {
		printf("%.2f",cost);
	}   
}