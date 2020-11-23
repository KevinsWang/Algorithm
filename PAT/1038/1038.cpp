#include<iostream>
#include<vector>
#include<algorithm>
#include <string>
using namespace std;

vector<string> line;

bool cmp(string x, string y)
{
    auto a = x.begin(), b = y.begin();
    while (a!=x.end() && b!=y.end())
    {
        if(*a == *b)
        {
            a++;b++;
        }
        else return *a < *b;
    }
    if(a!=x.end())  return cmp( x.substr(a - x.begin(), x.end() - a) , y);
    else if(b!=y.end()) return cmp( x , y.substr(b - y.begin(), y.end() - b));
    else return true;
}
//bool cmp(string x, string y) { return x + y < y + x;}

int main()
{
    int N;
    string p;
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>p;
        line.push_back(p);
    }
    sort(line.begin(), line.end(), cmp);
    // 需要考虑有0的情况
    // for (auto i = line.begin(); i != line.end(); i++)
    //     cout<<*i;
    string out;
    for (auto i = line.begin(); i != line.end(); i++)
        out += *i;
    int i;
    for (i = 0; i < out.size() && out[i] == '0'; i++);  // 将字符串头部的0全部扫掉
    if(i == out.size()) cout<<'0'<<endl;
    else cout<<out.c_str() + i <<endl;
}