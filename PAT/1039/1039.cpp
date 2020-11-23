#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;

int N,K;

unordered_map<string, set<int>> line;

int main()
{
    cin>>N>>K;
    while (K--)
    {
        int no, num;
        string name;
        scanf("%d%d", &no, &num);
        while (num--)
        {
            name.resize(4);
            scanf("%s", &name[0]);
            line[name].insert(no);
        }
        
    }
    string check_name;
    while (N--)
    {
        check_name.resize(4);
        scanf("%s", &check_name[0]);
        cout<<check_name<<" "<<line[check_name].size();
        if(line[check_name].size() != 0)
        {
            for (auto t: line[check_name])
            {
                cout<<" "<<t;
            }
        }
        cout<<endl;
    }
}