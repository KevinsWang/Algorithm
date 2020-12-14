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
        string line;
        cin>>line;
        int input = stoi(line.substr(0, line.size() - 1));
        float ans;
        ans = (float)(input * input)/((input * input) + (100 - input) * (100 - input));
        ans = ans * 100;
        printf("%.2f%\n", ans);
    }
    
}
