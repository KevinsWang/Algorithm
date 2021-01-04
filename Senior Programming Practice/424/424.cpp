#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int x, k, b;
    int out2, out3;
    while (cin>>x && x)
    {
        if(x <= 3)
        {
            cout<<x<<endl;
            continue;
        }
        k = x / 3;
        b = x % 3;
        switch (b)
        {
        case 0:
            out2 = 0;
            out3 = k;
            break;
        case 1:
            out2 = 2;
            out3 = k - 1;
            break;
        case 2:
            out2 = 1;
            out3 = k;
            break;
        default:
            break;
        }
        for (int i = 0; i < out2; i++) cout<<"2 ";
        for (int i = 0; i < out3; i++) cout<<"3 ";
        cout<<endl;
    }
}
