#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
typedef long long LL;
int main()
{
    LL x;
    cin>>x;
    int count = 0, b;
    do
    {
        b = x % 16;
        if(b == 0||b == 4||b == 6||b == 9||b == 10||b == 13) count++;
        else if(b == 8|| b == 11) count += 2;
        x /= 16;
    }while(x);
    cout<<count<<endl;
}
