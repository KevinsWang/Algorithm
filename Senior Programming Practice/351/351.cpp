#include<iostream>
#include<algorithm>
using namespace std;

int Month[12] = {31,30,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int month, day, ans = 0;
        cin>>month>>day;
        if (month < 8)
        {
            ans = Month[month-1] - day + 8;
        }
        else ans = 8 - day;
        for(int i = month;i < 7; i++)
        {
            ans += Month[i];
        }
        cout<<ans<<endl;
    }
}