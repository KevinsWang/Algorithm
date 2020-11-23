#include<iostream>
using namespace std;

string num[10]={
    "zero","one",
    "two","three",
    "four","five",
    "six","seven",
    "eight","nine"
};


int main()
{   
    string x;
    cin>>x;
    int sum = 0;
    for(int i = 0; i < x.size(); i++)
    {   
        sum += x.at(i) - '0';
    }
    x = to_string(sum);
    for (int i = 0; i < x.size(); i++)
    {
        int c = x[i] - '0';
        if(i == 0) cout<<num[c];
        else cout<<" "<<num[c];
    }
    
}