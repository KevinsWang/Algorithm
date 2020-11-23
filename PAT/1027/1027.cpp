#include<iostream>
#include<math.h>
using namespace std;
#include<string.h>
int main()
{
    int c[3];
    cin>>c[0]>>c[1]>>c[2];

    char out[6];
    char t[2];

    for (int i = 0; i < 3; i++)
    {
        int x = c[i];
        int flag = 0;
        for(;;flag++)
        {
            int y = x % 13;
            t[1 - flag] =  y < 10 ? '0' + y : 'A' + y -10;
            x /= 13;
            if(x == 0)
            {
                break;
            }
        }
        if(flag == 0) t[0] = '0';
        strncpy(out + i * 2, t, 2);
    }
    cout<<"#"<<out<<endl;
}