#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int x_m[2] = {-1, 1};
int y_m[2] = {-1, 1};

int main()
{
    int T,n,count,ans;
    double a,b,c,d;
    cin>>T;
    count = 1;
    while (count <= T)
    {
        ans = 0;
        cin>>n; 
        cin>>a>>b>>c>>d;  // a,b是起点，c,d是终点
        int next_x, next_y;
        while (1){   
            if(a == c && b == d) break;   
            if(a == c && abs(b-d) == 1 || b == d && abs(a-c) == 1){
                ans = -1;
                break;
            }    
            next_x = c > a;
            next_y = d > b;
            if(a + x_m[next_x] > n || a + x_m[next_x] < 1) a += x_m[next_x^1];
            else a += x_m[next_x];
            if(b + y_m[next_y] > n || b + y_m[next_y] < 1) b += y_m[next_y^1];
            else b += y_m[next_y];
            ans++;
        }
        cout<<"Case "<<count<<":"<<endl;
        cout<<ans;
        count++;
        if(count <= T)
            cout<<endl<<endl;
    }
}

