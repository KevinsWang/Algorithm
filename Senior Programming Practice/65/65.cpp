#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int a = 0,b = 0,ans = 0;
        float output;
        string line;
        cin>>line;
        for (int i = 0; i < line.size(); i++)
        {
            if(line[i] == 'U') b++;
            else if(line[i] == 'R')
            {
                a++;
                ans += b;
            }
        }
        output = (a * b) / 2.0 - ans;
        printf("%.3f\n", output);
    }
    
}
