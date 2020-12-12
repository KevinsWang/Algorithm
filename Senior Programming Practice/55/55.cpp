#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    string line;
    while (1)
    {
        getline(cin, line);
        if(line == "ENDOFINPUT") break;
        else if(line == "START" || line == "END") continue;
        for (int i = 0; i < line.size(); i++)
        {
            if(line[i] <= 'Z' && line[i] >= 'A')
            {
                line[i] -= 5;
                if(line[i] < 'A') line[i] += 26;
            }
        }
        cout<<line<<endl;
    }
    
}
