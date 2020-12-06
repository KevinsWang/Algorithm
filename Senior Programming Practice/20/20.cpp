#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int T,n,prex,p,x,count;
    cin>>T;
    count = 1;
    while (count <= T)
    {
        cin>>n;
        vector<int> line;
        prex = p = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            prex = x;
            x = x - p;
            p = prex;
            line.push_back(x);
        }
        sort(line.begin(), line.end());
        cout<<"Case "<<count<<":"<<endl;
        auto it = line.begin();
        cout<<*it;
        it++;
        for (; it != line.end(); it++) cout<<" "<<*it;  
        count++;
        if(count <= T)
            cout<<endl<<endl;
    }
    
}
