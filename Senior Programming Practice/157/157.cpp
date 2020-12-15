#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int n, T = 1;
    while (cin>>n && n != -1)
    {
        int a = 0, b = 0, x;
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            if(x == -1)
            {
                b++;
                a+=i;
            }
        }
        b = (b - 1)*b /2;
        cout<<"Case "<<T++<<": "<<a - b<<endl;
    }
}
