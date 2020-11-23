/**
 * @file 1044.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-09-14
 * 
 * @copyright Copyright (c) 2020
 * 
 * 超时了。。。。。。
 */
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


int main()
{
    int N,M;
    cin>>N>>M;
    int t[N + 1];
    vector<out> ans, minloss, output;
    int minmax = MAX;
    bool flag = false;
    for (int i = 1; i <= N; i++)
    {
        cin>>t[i];
        if(t[i] == M)
        {
            flag = true;
            ans.push_back(out(i,i));
        }
        else if(t[i] > M)
        {
            if(t[i] < minmax)
            {
                minmax = t[i];
                minloss.clear();
                minloss.push_back(out(i,i));
            }
            else if(t[i] == minmax) minloss.push_back(out(i,i));
        }
    }   
    int a,b;
    for (int i = 1; i <= N; i++)
    {
        b = t[i];
        for (int j = i + 1; j <= N; j++)
        {

            a = b + t[j];
            if(a == M)
            {
                flag = true;
                ans.push_back(out(i,j));
                break;
            }
            else if(a > M)
            {
                if(a < minmax)
                {
                    minmax = a;
                    minloss.clear();
                    minloss.push_back(out(i,j));
                    if(flag == false) break;
                }
                else if(a == minmax) minloss.push_back(out(i,j));
            }
            b = a;
        }
    }
    if(flag == true) output = ans;
    else output = minloss;

    sort(output.begin(),output.end(),less<out>());
    for (auto i = output.begin(); i != output.end(); i++)
        cout<<i->begin<<"-"<<i->end<<endl;
    
    
}