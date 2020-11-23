#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N,b;
vector<int> c;

int main()
{
    scanf("%d%d", &N, &b);
    int temp = N;
    while (temp)
    {
        c.push_back(temp % b);
        temp /= b;
    }
    bool flag = true;
    for (int i = 0, j = c.size() - 1; i < j; i++, j--)
    {
        if(c[i] != c[j])
        {
            flag = false;
            break;
        }
    }   
    if(flag) printf("Yes\n");
    else printf("No\n");
    int i = c.size() - 1;
    printf("%d", c[i--]);
    for (; i >= 0; i--)
    {
        printf(" %d", c[i]);
    }
}