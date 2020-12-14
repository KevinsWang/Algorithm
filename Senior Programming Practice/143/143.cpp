#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int m ,p ,n;
    while (cin>>m>>p>>n && m)
    {
        cout<<(p*n > m?p*n : m)<<endl; 
    }
    
}
