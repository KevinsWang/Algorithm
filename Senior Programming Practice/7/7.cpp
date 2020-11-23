#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,min;
    while (cin>>n)
    {
        int animal[n][8];
        min = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin>>animal[j][i];     
            }
        }
        for (int i = 0; i < n; i++)
        {
            sort(animal[i], animal[i] + 8);
            min += animal[i][0];
        }
        cout<<min<<endl;
        
    }
    
}