#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 0x7fffffff;
struct out
{
    int begin;
    int end;
    out(int _b, int _e)
    {
        begin = _b;
        end = _e;
    }
    bool operator < (const out & ths) const
    {
        return begin < ths.begin;
    }
};

int t[100002];
int main()
{
    int N,M;
    cin>>N>>M;
    int i,j;
    bool flag = false;
    int minmax = MAX;
    vector<out> ans, minloss, output;
    for (i = 1; i <= N; i++)
    {
        cin>>t[i];
    }
    i = 1;
    j = 1;
    int tmp;
    tmp = t[i];
    while (1)
    {
        while (j < N && tmp < M)
        {
            j++;
            tmp += t[j];
        }
        if(tmp == M)
        {
            ans.push_back(out(i,j));
            flag = true;
        }
        else if(tmp > M && flag == false)
        {
            if(tmp < minmax)
            {
                minmax = tmp;
                minloss.clear();
                minloss.push_back(out(i,j));
            }
            else if(tmp == minmax) minloss.push_back(out(i, j));
        }
        else if(j == N) break;
        tmp -= t[i];
        i++;
    }
    
    if(flag == true) output = ans;
    else output = minloss;

    sort(output.begin(),output.end(),less<out>());
    for (auto i = output.begin(); i != output.end(); i++)
        cout<<i->begin<<"-"<<i->end<<endl;
}