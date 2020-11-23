#include<iostream>
using namespace std;
int main()
{
    int x;
    while (cin>>x)
    {
        int a[3][3];
        float ans;
        a[0][0] = x;
        cin>>a[0][1]>>a[0][2];
        for (int i = 1; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin>>a[i][j];
        ans = abs(a[0][0]*a[1][1]*a[2][2]+a[1][0]*a[2][1]*a[0][2]+a[2][0]*a[1][2]*a[0][1]-(a[2][0]*a[1][1]*a[0][2]+a[0][1]*a[1][0]*a[2][2]+a[0][0]*a[2][1]*a[1][2]));
        printf("%.2f\n",ans);
    }
    
}