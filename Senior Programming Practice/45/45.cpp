#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
    char in[10002];
    int n;
    cin>>n;
    getchar();
    while (n--)
    {
        cin.getline(in,10000);
        int countWord = 0, index = 0;
        for (int i = 0; in[i] != '\0'; i++)
        {
            if(i == 0 && in[i] >= 'a' && in[i] <= 'z')
                in[i] -= 32;
            else if(i > 0 && in[i-1] != ' ' && in[i] <= 'Z' && in[i] >= 'A')
                in[i] += 32;
        }
        cout<<in<<endl;
    }
    
}
