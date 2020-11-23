#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<stack>
using namespace std;

vector<string> name;

struct fun
{
    int id;
    int shanru;
    int diaoyong;
    bool flag;
    vector<int> father;
    fun(int id_)
    {
        shanru = 1;
        diaoyong = 1;
        flag = true;
    }
};

vector<fun> f;
stack<int> st;
int main()
{
    int n;
    string m;
    int count = 0;
    do
    {
        cin>>n;
        if(n == 0) st.pop();
        else
        {
            cin>>m;
            fun tmp = fun(count);
            if(!st.empty())
            {
                tmp.father.pop_back(st.top());
                f[st.top()].flag = false;
            }
            f.push_back(tmp);
            name.push_back(m);
            st.pop(count);
            count++;
        }
    } while (!st.empty());
}
