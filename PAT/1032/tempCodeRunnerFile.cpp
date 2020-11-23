#include<iostream>
#include<map>
#include<string>
using namespace std;

typedef map<int, int> M;
typedef M::value_type v_t;

M::iterator it;
M m;
int x,y,z;
int N;
string t;


int main()
{
    cin>>x>>y>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>x>>t>>y;
        it = m.find(y);  
        if(it != m.end()) it->second++;
        else m[y] = 1;
    }
    if(m[-1] == 2) cout<<"-1"<<endl;
    else
    {
        for (it = m.begin(); it != m.end(); it++)
            if(it->second == 2)
            {
                cout<<it->first<<endl;
                break;
            } 
        
    }
}