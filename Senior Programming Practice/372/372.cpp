#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    while (cin>>n>>m && n)
    {
        vector<int> line(n);
        for (int i = 0; i < n; i++)
            cin>>line[i];
        sort(line.begin(),line.end());
        for (int i = 0; i < n; i += m)
            cout<<line[i]<<" ";
        cout<<endl;
    }
    
}