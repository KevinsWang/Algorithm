#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int n;
    while (cin>>n && n)
    {
        int minpush = n + 1;
        vector<int> line(n + 1, 0);
        vector<int> index(n + 1, 0);
        int x, temp;
        for (int i = 1; i <= n; i++)
        {
            cin>>x;
            temp = x;            
            if(x >= minpush)
            {
                line.push_back(i);
                continue;
            }
            while (line[x] != 0 && x < minpush) x += index[x];
            if(x >= minpush)
            {
                line.push_back(i);
                minpush = temp;
            }
            else 
            {
                line[x] = i;
                if(x < n) index[x] = 1 + index[x + 1];
                else index[x] = 1;
            }
        }
        
        for (int i = 1; i < line.size(); i++) cout<<line[i]<<" ";
        cout<<endl;
    }
}
