#include<bits/stdc++.h>
using namespace std;

bool is_prime(int x)
{
    if(x <= 1) return false;
    int y = int(sqrt(x * 1.0));
    for (int i = 2; i <= y; i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

int main()
{
    int n,d;
    while (scanf("%d",&n) != EOF)
    {
        if(n < 0 ) break;
        scanf("%d", &d);
        if(is_prime(n) == false)
        {
            cout<<"No"<<endl;
            continue;
        }
        int len = 0, arr[100];
        do
        {
            arr[len++] = n % d;
            n /= d;
        } while (n != 0);
        for (int i = 0; i < len; i++)
        {
            n = n * d + arr[i];
        }
        
        if(is_prime(n)) cout<<"Yes"<<endl; 
        else cout<<"No"<<endl; 
    }
    
}

