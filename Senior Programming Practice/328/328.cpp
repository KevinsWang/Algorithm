#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    char first[13] = {'`','1','2','3','4','5','6','7','8','9','0','-','='};
    vector<char> firstline(begin(first), end(first));
    char second[13] = {'Q','W','E','R','T','Y','U','I','O','P','[',']','\\'};
    vector<char> secondline(begin(second), end(second));
    char third[11] = {'A','S','D','F','G','H','J','K','L',';','\''};
    vector<char> thirdline(begin(third), end(third));
    char forth[10] = {'Z','X','C','V','B','N','M',',','.','/'};
    vector<char> forthline(begin(forth), end(forth));


    string line;
    while (getline(cin, line))
    {
        for (int i = 0; i < line.size(); i++)
        {
            vector<char>::iterator it;
            if(line[i] == ' ') line[i] = line[i];
            else if(find(firstline.begin(), firstline.end(), line[i]) != firstline.end()) 
            {
                it = find(firstline.begin(), firstline.end(), line[i]);
                line[i] =  *(it-1);
            }
            else if(find(secondline.begin(), secondline.end(), line[i]) != secondline.end()) 
            {
                it = find(secondline.begin(), secondline.end(), line[i]);
                line[i] =  *(it-1);
            }
            else if(find(thirdline.begin(), thirdline.end(), line[i]) != thirdline.end()) 
            {
                it = find(thirdline.begin(), thirdline.end(), line[i]);
                line[i] =  *(it-1);
            }
            else if(find(forthline.begin(), forthline.end(), line[i]) != forthline.end()) 
            {
                it = find(forthline.begin(), forthline.end(), line[i]);
                line[i] =  *(it-1);
            }
        }
        cout<<line<<endl;        
    }
    
}
