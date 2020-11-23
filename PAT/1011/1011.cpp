#include<iostream>
#include <iomanip>
using namespace std;


double in[3][3];
double out[3];
double Max;
char odd[3] = {'W', 'T', 'L'};
char outOdd[3];
int main()
{
    for (int i = 0; i < 3; i++)
    {
        Max = 0;
        for (int j = 0; j < 3; j++)
        {
            cin>>in[i][j];
            if(Max < in[i][j])
            {
                Max = in[i][j];
                outOdd[i] = odd[j];
            }
        }
        out[i] = Max;
        cout<<outOdd[i]<<" ";
    }
    double ans;
    ans = (out[0]*out[1]*out[2]*0.65-1) * 2;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<ans;
}