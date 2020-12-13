#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int x;
        cin>>x;
        if(x % 14 == 0) cout<<"snoopy wins the game!"<<endl;
        else cout<<"flymouse wins the game!"<<endl;
    }
}
