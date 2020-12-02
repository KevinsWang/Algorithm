#include<iostream>
#include<string>
using namespace std;

int main()
{
    string in;
    while (cin>>in)
    {
        if(in.compare("$") == 0) break;
        const char *it = in.c_str();
        for (int i = 1; i <= in.size(); i++, it++)
        {   
            int j = i % 26;
            if(*it - j < 65) cout<<char(*it - j + 26);
            else cout<<char(*it - j);
        }
        cout<<endl;
    }
}