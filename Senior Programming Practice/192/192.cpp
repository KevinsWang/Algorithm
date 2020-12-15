#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int n;
    while (cin>>n)
    {
        int x , ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin>>x;
                if(j != 0) cout<<" ";
                ans = 0;
                while (x)
                {
                    ans ^= (x & 1);
                    x >>= 1;
                }
                cout<<ans;
            }   
            cout<<endl;
        }
    }
}
