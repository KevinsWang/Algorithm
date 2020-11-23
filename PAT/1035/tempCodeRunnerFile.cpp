#include<iostream>
#include<vector>
using namespace std;

struct account
{
    char name[10];
    char psword[10];
};

vector<account> line;
int N,cnt = 0;

bool check(char * t)
{
    bool flag = false;
    while (*t != '\0')
    {
        switch (*t)
        {
        case '1':
            *t = '@';
            flag = true;
            break;
        case '0':
            *t = '%';
            flag = true;
            break;
        case 'l':
            *t = 'L';
            flag = true;
            break;
        case 'O':
            *t = 'o';
            flag = true;
            break;
        default:
            break;
        }
        t++;
    }
    return flag;
}

int main()
{
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        account tmp;
        cin>>tmp.name>>tmp.psword;
        if(check(tmp.psword))
        {
            cnt++;
            line.push_back(tmp);
        }
    }
    if(cnt == 0) printf("There is %d account and no account is modified", N);
    else
    {
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; i++)
            printf("%.10s %s\n", line[i].name, line[i].psword );
    }
    
}