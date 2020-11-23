#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cstring>
#include <map>
#include <stack>
#include <set>

using namespace std;
#define MAX 2010


struct node{
    string id;
    int g[4];
    int rank, subject;
    node() {rank = MAX; subject = -1;};
};

node list[MAX];
int r[MAX];
map<string, int>str2int;
char subject[4] = {'A','C','M','E'};

int p = 0;
bool cmp(int a, int b)
{
    return list[a].g[p] > list[b].g[p];
}

int main()
{
    int n,k;
    cin>>n>>k;
    //初始化
    for (int i = 1; i <= n; i++)
    {
        cin>>list[i].id>>list[i].g[1]>>list[i].g[2]>>list[i].g[3];
        list[i].g[0] = list[i].g[1] + list[i].g[2] + list[i].g[3];
        r[i] = i;
        str2int[list[i].id] = i;  // 将ID和编号相关联起来
    }

    for (int i = 0; i < 4; i++)  // 四个考核指标，均分+三门课
    {
        p = i;   //当前是哪一个考核指标
        sort(&r[1],&r[1]+n,cmp);   // 重点
        int nowR = 1;              // 当前的排名，第一名
        int preG = list[r[1]].g[p]; // 当前考核的第一名的成绩
        for (int j = 1; j <= n; j++)
        {
            int nowP = r[j];        // 此次考核排名的当前编号
            if(preG == list[nowP].g[p])   // 出现分数一样的情况，则排名还和前一名一样
            {
                if(nowR < list[nowP].rank)
                {
                    list[nowP].rank = nowR;
                    list[nowP].subject = p;
                }
            }
            else
            {
                nowR = j;           // 名次向后移动
                preG = list[nowP].g[p];
                if(list[nowP].rank > nowR)
                {
                    list[nowP].rank = nowR;
                    list[nowP].subject = p;
                }
            }
            
        }
        
    }

    string check;
    for (int i = 0; i < k; i++)
    {
        cin>>check;
        int nowP = str2int[check];
        if(nowP == 0) cout<<"N/A"<<endl;
        else
        {
            cout<<list[nowP].rank<<" "<<subject[list[nowP].subject]<<endl;
        }
        
    }
    
    return 0;
    
}