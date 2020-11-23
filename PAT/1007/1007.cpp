#include<iostream>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int in[N], sum=0 , x=0 , y=0, max = -1, maxl = 0, maxr = N - 1;
    for (int i = 0; i < N; i++)
    {
        cin >> in[i];
        if (sum+in[i] >= 0)
        {
            y = i;
            sum += in[i];
            if(sum > max)
            {
                max = sum;
                maxl = x;
                maxr = y;
            }
        }
        else
        {
            sum = 0;
            x = i + 1;
        }
    }
    if(max < 0) max = 0;
    cout<<max<<" "<<in[maxl]<<" "<<in[maxr];
    return 0;
}