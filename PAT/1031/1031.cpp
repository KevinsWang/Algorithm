#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    string t, space;
    cin>>t;
    int b, l;
    l = (t.length() + 2) / 3;
    b = t.length() + 2 - l * 2;
    space.resize(b-2);
    fill(space.begin(), space.end(), ' ');
    for (int i = 0; i < l - 1; i++)
    {
        cout<<t[i]<<space<<t[t.length() - 1 - i]<<endl;
    }
    cout<<t.substr(l-1, b)<<endl;
}