#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;
int main()
{
    int n,x,y;
    while (cin>>n)
    {
        map<int, set<int> > m;
        for (int i = 0; i < n; i++)
        {
            cin>>x>>y;
            m[x].insert(y);
        }
        float axis = 0, tmp = 0;
        bool flag = true, isSym = true;
        for (auto i = m.begin(); i != m.end(); i++)
        {
            auto a = i->second.begin();
            auto b = i->second.end();
            b--;
            if(flag)
            {
                flag = false;
                axis = (*a + *b) / 2.0;
            }
            while (*a < *b)
            {
                tmp = (*a + *b) / 2.0;
                if(tmp != axis)
                {
                    isSym = false;
                    break;
                }
                a++;b--;
            }
            if(a == b && *a != axis) isSym = false; 
            if(!isSym) break;
        }
        cout<<(isSym ? "YES" :"NO")<<endl;
    } 
}