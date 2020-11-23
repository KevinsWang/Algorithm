#include<iostream>
#include<vector>
using namespace std;

vector<string> id;
typedef struct time
{
    int h;
    int m;
    int s;
    int sum;
    time(string str)
    {
        h = stoi(str.substr(0,2));
        m = stoi(str.substr(3,5));
        s = stoi(str.substr(6,8));
        sum = h*3600 + m*60 + s;
    }
    void change(const time & a)
    {
        h = a.h;
        m = a.m;
        s = a.s;
        sum = a.sum;
    }
    bool operator < (const time & a) const
    {
        return sum < a.sum;
    }
    bool operator > (const time &a) const
    {
        return sum > a.sum;
    }
}Time;


int main()
{
    int M;
    cin>>M;
    Time Max = Time("00:00:00");
    Time Min = Time("23:59:59");
    int x = 0,y = 0;
    for (int i = 0; i < M; i++)
    {
        string s;
        cin>>s;
        id.push_back(s);
        cin>>s;
        Time tmp1 = Time(s);
        if(tmp1 < Min)
        {
            Min.change(tmp1);
            x = i;
        }
        cin>>s;
        Time tmp2 = Time(s);
        if(tmp2 > Max)
        {
            Max.change(tmp2);
            y = i;
        }
    }    
    cout<<id[x]<<" "<<id[y];
}