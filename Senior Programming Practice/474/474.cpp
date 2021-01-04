#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int line1[20], line2[20];
    int n;
    int count = 0;
    cin>>n;
    for (int i = 0; i < n; i++) cin>>line1[i];
    while (line1[0] != 0)
    {
        int i,j;
        for (i = 0; i < line1[0]; i++) line2[i] = line1[i + 1];
        line2[i++] = line1[0];
        for (; i < n; i++) line2[i] = line1[i];
        count++;
        for (i = 0; i < n; i++) line1[i] = line2[i];
    }
    cout<<count;
    
}
