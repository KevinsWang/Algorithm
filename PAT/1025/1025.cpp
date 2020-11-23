#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

struct st
{
    char id[13];
    int score;
    int final_rank;
    int local_num;
    int local_rank;
};

st line[30001];

bool cmp(st a, st b)
{
    if(a.score == b.score) return strcmp(a.id, b.id) < 0;
    return a.score > b.score;
}

int N,k;

int main()
{
    cin>>N;
    int at = 0;
    for (int i = 0; i < N; i++)
    {
        cin>>k;
        for (int j = 0; j < k; j++)
        {
            cin>>line[at + j].id>>line[at + j].score;
            line[at + j].local_num = i + 1;
        }
        sort(line + at, line + at + k, cmp);
        int rank = 1;
        line[at].local_rank = rank;
        for (int j = 1; j < k; j++)
        {
            if(line[at+j].score == line[at + j - 1].score) line[at + j].local_rank = line[at + j - 1].local_rank;
            else line[at + j].local_rank = j + 1;
        }
        at = at + k;    
    }
    sort(line, line + at, cmp);
    int rank = 1;
    line[0].final_rank = rank;
    for (int j = 1; j < at; j++)
    {
        if(line[j].score == line[j - 1].score) line[j].final_rank = line[j - 1].final_rank;
        else line[j].final_rank = j + 1;
    }
    printf("%d\n", at);
    for (int i = 0; i < at; i++)
    {
        printf("%s %d %d %d\n", line[i].id, line[i].final_rank, line[i].local_num, line[i].local_rank);
    }
    
}