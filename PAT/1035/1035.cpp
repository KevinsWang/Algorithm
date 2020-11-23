#include<iostream>
#include<vector>
using namespace std;

struct account
{
    string name;
    string psword;
};

vector<account> line;
int N,cnt = 0;



int main()
{
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        account tmp;
        cin>>tmp.name>>tmp.psword;
        bool flag = false;
        for (int i = 0; i < tmp.psword.size(); i++)
        {
            switch (tmp.psword[i])
            {
            case '1':
                tmp.psword[i] = '@';
                flag = true;
                break;
            case 'l':
                tmp.psword[i] = 'L';
                flag = true;
                break;
            case '0':
                tmp.psword[i] = '%';
                flag = true;
                break;
            case 'O':
                tmp.psword[i] = 'o';
                flag = true;
                break;
            default:
                break;
            }
        }
        if(flag)
        {
            line.push_back(tmp);
            cnt++;
        }
    }
    if(cnt == 0) 
    {
        if (N==1) printf("There is 1 account and no account is modified\n");
		else printf("There are %d accounts and no account is modified\n",N);
    }
    else
    {
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; i++)
            cout<<line[i].name<<" "<<line[i].psword<<endl;

    }
    
}