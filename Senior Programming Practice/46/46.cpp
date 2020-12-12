#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n, count = 0, x, temp;
        vector<int> line;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            line.push_back(x);
        }
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if(line[j] > line[j + 1])
                {
                    swap(line[j], line[j + 1]);
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
}
