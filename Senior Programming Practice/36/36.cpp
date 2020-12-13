#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
string ans[501];

string addstr(string x, string y)
{
    string temp;
    if(x.length() < y.length()) // ensue that x is longer than y
    {
        temp = x;
        x = y;
        y = temp;
    }
    int i,j;
    for(i = x.length() - 1, j = y.length() - 1; i >= 0; i--, j--)
    {
        x[i] = (x[i] + (j>=0?y[j] - '0' : 0));
        if(x[i] > '9')
        {
            x[i] -= 10;
            if(i) x[i - 1]++;
            else x = "1" + x;
        }
    }
    return x;
}

void find()
{
    ans[1] = "1"; ans[2] = "2"; ans[3] = "4";
    for (int i = 4; i <= 500; i++)
    {
        ans[i] = addstr(ans[i - 1],ans[i - 2]);
        ans[i] = addstr(ans[i],ans[i-3]);
    }
}

int main()
{
    find();
    int x;
    while (cin>>x)
    {
        if(x == 0) break;
        cout<<ans[x]<<endl;
    }
}
