#include<iostream>
#include<string>
using namespace std;

string in;
int maxn = 0;
int scan(int l, int r, int cnt)
{
    while (l >= 0 && r < in.size())
        {
            if(in[l] == in[r])
            {
                cnt += 2;
                l--;r++;
            }
            else break;
        }
    return cnt;
}

int main()
{
    
    getline(cin,in);
    
    for (int i = 0; i < in.size(); i++)
    {
        int x;
        if(i>0 && in[i] == in[i-1]) x = scan(i-1, i, 0);
        else if(i<in.size() && in[i] == in[i+1]) x = scan(i, i+1, 0); 
        else x = scan(i-1, i+1, 1);
        if(x > maxn) maxn = x;
    }
    cout<<maxn<<endl;
}