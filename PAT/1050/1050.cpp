#include<iostream>
#include<string>
#include<map>
using namespace std;

string a,c;
map<char, int> m;
char b;
int main()
{
    getline(cin, a);
    //getchar();
    while ((b = getchar()) != '\n')
    {
        m[b]++;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if(!m[a[i]]) c.push_back(a[i]);
    }
    cout<<c<<endl;
}
