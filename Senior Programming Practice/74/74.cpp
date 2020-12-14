#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int T, n, x, MAX, ans;
    cin>>T;
    while (T--)
    {
        cin>>n;
        ans = -1;
        vector<int> line;
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            line.push_back(x);
        }
        sort(line.begin(), line.end());
        MAX = line[line.size() - 1];
        int i = 0, j = line.size() - 2;
        while (i < j)
        {
            int temp = line[i] + line[j];
            if(temp == MAX)
            {
                ans = MAX;
                break;
            }
            else if(temp > MAX) j--;
            else if(temp < MAX) i++;
        }
        cout<<ans<<endl;
    }
    
}
