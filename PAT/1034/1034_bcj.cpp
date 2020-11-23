#include<iostream>
#include<map>
#include<set>
#include<vector>

using namespace std;

typedef map<string, int> M;
typedef M::value_type v_t;

M m;
int father[2001];
int rtime[2001];
int cnt[2001];
int totaltime[2001];
M::iterator it;
set<int> gang;
set<string> ans;
int findF(int x)
{
    int a = x, max = rtime[x], i = x;
    while (x != father[x])
    {
        x = father[x];
        if(max < rtime[x])
        {
            max = rtime[x];
            i = x;
        }
    }
    father[i] = i;
    father[x] = i;
    x = i;
    while (a != father[a])
    {
        int z = a;
		a = father[a];
		father[z] = x;
    }
    return x;
}

void unions(int x, int y)
{
    int a = findF(x);
    int b = findF(y);
    if(a != b)
    {
        father[a] = father[b] = rtime[a] > rtime[b] ? a:b;
    }
}

int main()
{
    int N,K;
    cin>>N>>K;
    int num = 0;
    for (int i = 0; i < N; i++)
    {
        string a,b;
        int t;
        cin>>a>>b>>t;
        it = m.find(a);
        if(it != m.end())
        {
            int index = m[a];
            rtime[index] += t; 
        } 
        else
        {
            rtime[num] = t;
            father[num] = num;
            m.insert(v_t(a,num++));
        }
        it = m.find(b);
        if(it != m.end())
        {
            int index = m[b];
            rtime[index] += t; 
        } 
        else
        {
            rtime[num] = t;
            father[num] = num;
            m.insert(v_t(b,num++));
        }
        unions(m[a], m[b]);
    }
    for (int i = 0; i < num; i++)
    {                     // 此处不要在findF了
        cnt[father[i]]++; 
        totaltime[father[i]] += rtime[i] / 2;
    }
    for (int i = 0; i < num; i++)
    {
        if(cnt[i] > 2 && totaltime[i] > K)
            gang.insert(i);       
    }
    int count = gang.size();
    cout<<gang.size()<<endl;
    if(count == 0)
        return 0;
    else
    {
        for (auto i = gang.begin(); i != gang.end() ; i++)
        {
            for (auto j = m.begin(); j != m.end(); j++)
            {
                if( j->second == *i) ans.insert(j->first);
            }
        }
        for (auto i = ans.begin(); i != ans.end(); i++)
        {
            cout<<*i<<" "<<cnt[m[*i]]<<endl;
        }
    }
}



