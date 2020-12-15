#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    int r,c;
    while (cin>>r>>c && r != 0)
    {
        char g;
        int group[r+1][c+1];    
        int ans = 0;
        memset(group, 0 , sizeof(group));
        for (int i = 1; i <= r; i++)
        {
            for (int j = 0; j <= c; j++)
            {
                cin>>g;
                if(g == 'O')
                {
                    group[i][j] == ++ans;
                }
            }
            
        }
        
    }
    
}
