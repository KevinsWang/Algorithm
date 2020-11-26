#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int N;
    double ans,a,b,c,cosa;
    int ax,ay,bx,by,cx,cy;
    cin>>N;
    while (N--)
    {
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        a = sqrt(pow((bx - cx), 2) + pow((by - cy), 2));
        b = sqrt(pow((ax - cx), 2) + pow((ay - cy), 2));
        c = sqrt(pow((bx - ax), 2) + pow((by - ay), 2));
        cosa = (b*b + c*c - a*a)/ (2.0*b*c);
        ans = 2 * b * c * (1 - cosa*cosa) / a;
        printf("%.3f\n", ans);
    }
    
}