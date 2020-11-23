#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;
/**
 * @brief 这个想法挺好，但题目中是only a permutation of the digits in the original number，
 * 不仅要位数一样，而且出现数的个数也要一致
 */
/*
long long n, m;
int t;

int main()
{
    scanf("%lld", &n);
    m = n;
    set<int> a,b;
    while (m)
    {
        t = m % 10;
        a.insert(t);  
        m /= 10;
    }
    m = n * 2;
    while (m)
    {
        t = m % 10;
        b.insert(t);  
        m /= 10;
    }
    bool flag = true;
    if(a.size() != b.size() || t >= 5) flag = false;
    else
    {
        for(auto i = a.begin(), j = b.begin(); i != a.end(); i++, j++)
            if(*i != *j)
            {
                flag = false;
                break;
            }
    }    
    if(!flag) printf("No\n");
    else printf("Yes\n");
    printf("%lld", n * 2);
} */

string in, out;
int cnt[10] = {0};
int flag1 = 0, flag2 = 0;

int main()
{
    cin>>in;

    int len = in.length();
    // 原来的用加， 加倍后的用减
    out.resize(len + 1);
    for (int i = len - 1; i >= 0; i--)
    {
        int temp = in[i] - '0';
        cnt[temp]++;
        temp = temp * 2 + flag1;
        if(temp >= 10)
        {
            temp = temp - 10;
            flag1 = 1;
        }
        else
        {
            flag1 = 0;
        }
        cnt[temp]--;
        out[i] = temp + '0';
    }
    
    for (int i = 0; i < 10; i++)
    {
        if(cnt[i] != 0) flag2 = 1;
    }
    printf("%s", (flag1 == 1 || flag2 == 1) ? "No\n" : "Yes\n");
    if(flag1 == 1) printf("1");
    cout<<out<<endl;
}

