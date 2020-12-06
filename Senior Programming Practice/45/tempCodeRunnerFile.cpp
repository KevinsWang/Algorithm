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
            if(countWord == 0 && i == 0 && in[i] >= 97)
                in[i] -= 32;
            if(in[i] == ' '){
                countWord++;
                index = i;
            }
            else if(countWord != 0 && i != index + 1 && in[i] < 97)
                in[i] += 32;
        }
        cout<<in<<endl;
    }
    
}
