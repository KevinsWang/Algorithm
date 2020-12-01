#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string in;
    while (cin>>in)
    {
        if(in == "$") break;
        const char *it = in.c_str();
        for (int i = 1; i <= in.size(); i++, it++)
        {   
            cout<<char((*it - i + 65)%65);
        }
        cout<<endl;
    }
}