#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    string line;
    int t = 1;
    while (getline(cin,line) && line != "#")
    {
        for (int i = 0; i < line.size(); i++)
        {
            if(i % 2 == 1 && line[i] <= 'z' && line[i] >= 'a')
                line[i] -= 32;
        }
        cout<<"Case "<<t++<<": "<<line<<endl;
    }
    
}
