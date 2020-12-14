#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n,m;
    while (cin>>n)
    {
        cin>>m;
        int x , minp;
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            if(i == 0) minp = x;
            if(minp > x) minp = x; 
        }
        cout<<m/minp<<endl;
    }
    
}
