#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct st
{
    string name;
    string id;
    int grade;
};
vector<st> M,F;
int N;
bool cmp(st x, st y)
{
    return x.grade < y.grade;
}

int main()
{
    cin>>N;
    vector<st>::iterator fh, ml;
    for (int i = 0; i < N; i++)
    {
        st tmp;
        char gender;
        cin>>tmp.name>>gender>>tmp.id>>tmp.grade;
        if(gender == 'M') M.push_back(tmp);
        else F.push_back(tmp);
    }
    if(F.empty()) cout<<"Absent"<<endl;
    else
    {
        sort(F.begin(), F.begin() + F.size(), cmp);
        fh = F.end() - 1;
        cout<<fh->name<<" "<<fh->id<<endl;
    }
    if(M.empty()) cout<<"Absent"<<endl;
    else
    {
        sort(M.begin(), M.begin() + M.size(), cmp);
        ml = M.begin();
        cout<<ml->name<<" "<<ml->id<<endl;
    }
    if(F.empty() || M.empty())  cout<<"NA"<<endl;
    else cout<<fh->grade - ml->grade<<endl;
}