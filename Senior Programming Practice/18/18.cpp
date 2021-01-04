#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

int main()
{
    int N;
    while (cin>>N && N)
    {
        vector<int> target(N + 1);
        vector<bool> visit(N + 1, false);
        vector<int> h(65538);
        int x, cost = 0, minn = 65539;
        for (int i = 1; i <= N; i++)
        {
            cin>>x;
            if(minn > x) minn = x;
            h[x] = i;
            cost += x;          // 每个位置上的值都要移动一次
        }   
        for (int i = 1; i <= N; i++) cin>>target[i];
        int q, count, inmin;
        for (int i = 1; i <= N ; i++)
        {
            if(visit[i]) continue;
            count = 0;
            q = i;
            inmin = 65539;
            do
            {
                if(inmin > target[q]) inmin = target[q];
                count++;
                visit[q] = true;
                q = h[target[q]];
            } while (q != i);
            int cost1 = (count - 2) * inmin;
            int cost2 = (count + 1) * minn + inmin;
            cost += min(cost1, cost2);
        }
        cout<<cost<<endl;
    }
    
}
