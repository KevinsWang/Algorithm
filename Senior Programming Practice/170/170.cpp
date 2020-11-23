#include<iostream>
#include<set>
using namespace std;

set<int> line;

int main()
{
    int x;
    scanf("%d", &x);
    while (x != 0)
    {
        line.insert(x);
        scanf("%d", &x);
    }
    auto i = line.begin();
    cout<< *i;
    i++;
    for (; i != line.end(); i++)
    {
        cout<<" "<<*i;
    }
    
}
