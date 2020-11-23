#include<iostream>
#include<map>
using namespace std;

map<int, int> m;
map<int, int> :: iterator it_m;
int main()
{
    int N, x, y;
    double M;
    while(scanf("%d", &N) != EOF)
    {
        m.erase(m.begin(), m.end());
        M = N / 2.0;
        for (int i = 0; i < N; i++)
        {   
            scanf("%d", &x);
            m[x]++;
            if(m[x] >= M)
            {
                y = x;
            }    
        }
        cout<<y<<endl;
    }
}