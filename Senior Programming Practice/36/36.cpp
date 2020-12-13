#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int ans[501];

void find()
{
    ans[1] = 1;ans[2] = 2;ans[3] = 4;
    for (int i = 4; i <= 500; i++)
    {
        ans[i] = ans[i - 3] * ans[3] + ans[i - 2] * ans[2] + ans[i - 1] * ans[1];
    }
}

int main()
{
    find();
    int x;
    while (cin>>x)
    {
        if(x == 0) break;
        cout<<ans[x]<<endl;
    }
    
}
