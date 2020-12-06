#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int x;
    while (cin>>x)
    {
        if(x == 0) break;
        cout<<ceil(x/2.0)<<endl;
    }
}