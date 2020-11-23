#include<iostream>
#include<string>
using namespace std;

string a[56], b[56], tmp[56];
int order[56];
char card[4] = {'S','H','C','D'};
int main()
{   

    for (int i = 1; i < 53; i++)
    {
        int index = ( i - 1 ) / 13, no = i % 13;
        string t;
        if(no == 0) t = "13";
        else if(no <10) t = no + '0';
        else
        {
            t = "1";
            t.push_back(no - 10 + '0');
        }
        a[i] = card[index] + t;
    }
    a[53] = "J1";a[54] = "J2";
    copy(a, a + 56, b);
    int N;
    cin>>N;
    for (int i = 1; i <= 54; i++)
    {
        cin>>order[i];
    }
    while (N--)
    {
        for (int i = 1; i <= 54; i++)
        {
            b[order[i]] = a[i];
        }
        copy(b, b+56, a);
    }
    cout<<b[1];
    for (int i = 2; i <= 54; i++)
    {
        cout<<" "<<b[i];
    }
    
}
