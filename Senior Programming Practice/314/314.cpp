#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m && n)
    {
        int maxm = 0, num;
        long long int temp;
        for (int i = n; i <= m; i++)
        {
            num = 1;
            temp = i;
            while (temp > 1)
            {
                if(temp % 2 == 0) temp /= 2;
                else         temp = temp * 3 + 1;
                num++;
            }
            maxm = max(maxm, num);
        }
        cout<<maxm<<endl;
    }
}