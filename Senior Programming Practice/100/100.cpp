#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        string line;
        string str[8] = {
            "littleken",
            "knuthocean",
            "dongfangxu",
            "zap",
            "kittig",
            "robertcui",
            "forest",
            "flirly"
        };
        int M[8];
        memset(M, 0 ,sizeof(M));
        cin>>line;
        for (int i = 0; i < line.size(); i++)
        {
            switch (line[i])
            {
            case 'l':
                i = i + str[0].size() - 1;
                M[0]++;
                break;
            case 'k':
                if(line[i + 1] == 'n')
                {
                    i = i + str[1].size() - 1;
                    M[1]++;
                }
                else
                {
                    i = i + str[4].size() - 1;
                    M[4]++;
                }
                break;
            case 'd':
                i = i + str[2].size() - 1;
                M[2]++;
                break;
            case 'z':
                i = i + str[3].size() - 1;
                M[3]++;
                break;
            case 'r':
                i = i + str[5].size() - 1;
                M[5]++;
                break;
            case 'f':
                if(line[i + 1] == 'o')
                {
                    i = i + str[6].size() - 1;
                    M[6]++;
                }
                else
                {
                    i = i + str[7].size() - 1;
                    M[7]++;
                }
                break;
            default:
                break;
            }
        }
        int MAX = 0, index = 0;
        for (int i = 0; i < 8; i++)
        {
            if(MAX < M[i])
            {
                index = i;
                MAX = M[i];
            }
        }
        cout<<str[index]<<endl;
    }
}
