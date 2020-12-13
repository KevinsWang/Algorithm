#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
    int n,x;
    while (cin>>n)
    {
        set<int> input;
        for(int i=0; i < n ; i++) 
        {
            cin>>x;
            input.insert(x);
        }
        auto it = input.begin();
        cout<<*it++;
        while (it != input.end())
        {
            cout<<" "<<*it++;
        }
        cout<<endl;
    }
    
}