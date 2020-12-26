#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct location
{
    int x,y;
};

int mv[8][2] = {
     1, 0,
     1, 1,
     0, 1,
    -1, 1,
    -1, 0,
    -1,-1,
     0,-1,
     1,-1
};

int main()
{
    int T, m, n, k;
    cin>>T;
    while (T--)
    {
        cin>>m>>n;
        char table[m + 1][n + 1];
        vector<location> index[26];
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin>>table[i][j];
                if(table[i][j] <= 'Z') table[i][j] += 32;
                location tmp;
                tmp.x = i;tmp.y = j;
                index[table[i][j] - 'a'].push_back(tmp);
            }
        }
        cin>>k;
        string word;
        for (int i = 0; i < k; i++)
        {
            cin>>word;
            for (int j = 0; j < word.size(); j++)
            {
                if(word[j] <= 'Z') word[j] += 32; 
            }
            bool flag = false;
            vector<location>::iterator it = index[word[0] - 'a'].begin();
            for (; it < index[word[0] - 'a'].end(); it++)
            {
                int x = it->x, y = it->y;
                for (int j = 0; j < 8; j++)
                {
                    if(x + mv[j][0] * word.size() > m + 1 || x + mv[j][0] * word.size() < 0 || y + mv[j][1] * word.size() > n + 1 || y + mv[j][1] * word.size() < 0)
                        continue;
                    else
                    {
                        int l = 0;
                        for (; l < word.size() && word[l] == table[x + mv[j][0] * l][y + mv[j][1] * l]; l++);
                        if(l == word.size())
                        {
                            flag = true;
                            break;
                        }
                    }
                }
                if(flag == true) 
                {
                    cout<<x<<" "<<y<<endl;
                    break;
                }
            }
            
        }
        
    }
    
}
