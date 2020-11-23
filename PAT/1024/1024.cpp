#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

string a;
int k;

bool isPalindromic(string x)
{
    bool flag = true;
    for (int i = 0; i < x.length(); i++)
        if(x[i] != x[x.length() - i - 1])
        {
            flag = false;
            break;
        }
    return flag;
}
/**
 * @brief 因为两个数是顺序相反的数，所以从string的begin开始加和end开始加是一样的
 * 
 */
string addstr(string a, string b)
{
    auto i1 = a.begin();
    auto i2 = b.begin();

    string res;
    int flag = 0, temp = 0;

    for(;i1 != a.end() && i2 != b.end(); i1++ , i2++)
    {
        temp = (*i1 - '0') + (*i2 - '0') + flag;
        flag = temp>9 ? 1 : 0;
        res.push_back((temp%10)+'0');
    }

    while (i1 != a.end())
    {
        temp = (*i1 - '0') + flag;
        flag = temp>9 ? 1 : 0;
        res.push_back((temp%10)+'0');
    }
    while (i2 != b.end())
    {
        temp = (*i2 - '0') + flag;
        flag = temp>9 ? 1 : 0;
        res.push_back((temp%10)+'0');
    }

    if(flag) res.push_back(flag + '0');

    reverse(res.begin(),res.end());

    return res;
}

int main()
{
    cin>>a>>k;
    int i;
    for (i = 0; i < k && !isPalindromic(a); i++)
    {
        string b;
        b = a;
        reverse(b.begin(), b.end());    
        a = addstr(a,b);
    }
    cout<<a<<endl;
    cout<<i<<endl;
}