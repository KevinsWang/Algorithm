#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;


struct st
{
    char id[6];
    char name[8];
    int score;
};

vector<st> line;
int N,C;

bool cmp(st x, st y)
{
    switch (C)
    {
    case 1:
        return strcmp(x.id, y.id) < 0;
        break;
    case 2:
        if(strcmp(x.name, y.name) == 0) return strcmp(x.id, y.id) < 0;
        return strcmp(x.name, y.name) < 0;
    case 3:
        if(x.score == y.score) return strcmp(x.id, y.id) < 0;
        return x.score < y.score;
    default:
        break;
    }
    return false;
}

int main()
{
    scanf("%d%d", &N, &C);

    for (int i = 0; i < N; i++)
    {
        st t;
        scanf("%s %s %d", t.id, t.name, &t.score);
        line.push_back(t);
    }
    sort(line.begin(), line.begin() + N, cmp);

    for (int i = 0; i < N; i++)
    {
        printf("%.6s %s %d\n", line[i].id, line[i].name, line[i].score);
    }
    
}






