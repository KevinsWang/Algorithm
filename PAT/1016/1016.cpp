#include<bits/stdc++.h>
using namespace std;


struct record
{
    string month;
    vector<long> on;
    vector<long> off;

};

struct compare
{
    bool operator()(const string &l, const string &r) const
    {
        if(strcmp(l.c_str(),r.c_str())==1)
            return true;
        else return false;
    }
};

int toll[25];
double daytoll = 0;
int N;
typedef map<string, record, compare> M;
M m;

int date2min(string s)
{
    int d = stoi(s.substr(0,2));
    int h = stoi(s.substr(3,2));
    int m = stoi(s.substr(6,2));
    return 1440*d + 60*h + m;
}

double calrest(int h, int m)
{
    double ans = 0;
    for (int i = h; i < 24; i++)
    {
        ans = ans + toll[i] * 60;
    }
    ans =  ans - toll[h] * m;
    return ans/100;
}


double min2money(int begin, int end)
{
    int d1 = begin / 1440, d2 = end / 1440;
    int h1 = (begin % 1440) / 60, h2 = (end % 1440) / 60;
    int m1 = begin - 1440 * d1 - 60 * h1, m2 = end - 1440 * d2 - 60 * h2;
    double c1,c2;
    c1 = calrest(h1,m1);
    c2 = calrest(h2,m2);
    if(d1 == d2) return c1 - c2;
    else{
        return (d2 - d1) * daytoll + c1 - c2;
    }
}

void printdate(int begin)
{
    int d1 = begin / 1440;
    int h1 = (begin % 1440) / 60;
    int m1 = begin - 1440 * d1 - 60 * h1;
    if(d1 < 10) cout<<"0";
    cout<<d1<<":";
    if(h1 < 10) cout<<"0";
    cout<<h1<<":";
    if(m1 < 10) cout<<"0";
    cout<<m1<<" ";
}

int main()
{
    for (int i = 0; i < 24; i++)
    {
        cin>>toll[i];
        daytoll += toll[i] * 60;
    }
    daytoll /= 100;
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        string name;
        string date;
        string line;
        cin>>name>>date>>line;
        M::iterator It = m.find(name);
        if(It == m.end())
            m.insert(M::value_type(name,record()));
        It = m.find(name);
        (*It).second.month = date.substr(0,2);
        int min = date2min(date.substr(3,8));
        if(line[1] == 'n') (*It).second.on.push_back(min);
        else (*It).second.off.push_back(min);
    }
    M::reverse_iterator It = m.rbegin();
    while(It != m.rend())
    {
        bool flag_cost = false, flag_print = false;
        sort((*It).second.on.begin(), (*It).second.on.end());
        sort((*It).second.off.begin(), (*It).second.off.end());
        vector<long>::iterator i = (*It).second.on.begin();
        vector<long>::iterator j = (*It).second.off.begin();
        double cost = 0;
        while (i < (*It).second.on.end() && j < (*It).second.off.end())
        {
            if( *i < *j && (*(i+1) > *j || i + 1 == (*It).second.on.end()) )
            {
                int min = *j - *i;
                double money = min2money(*i, *j);
                if(flag_print == false) 
                {
                    cout<<(*It).first<<" "<<(*It).second.month<<endl;
                    flag_print = true;
                }
                flag_cost = true;
                printdate(*i);
                printdate(*j);
                cost += money;
                cout<<min<<" $"<<setiosflags(ios::fixed)<<setprecision(2)<<money<<endl;
                i++;j++;
            }
            else if(*(i+1) < *j)
            {
                i++;
            }
            else j++;
        }
        if(flag_cost == true)
            cout<<"Total amount: $"<<setiosflags(ios::fixed)<<setprecision(2)<<cost<<endl;
        It++;
    }
    
}