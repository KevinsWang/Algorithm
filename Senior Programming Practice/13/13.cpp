#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
    string in;
    while (cin>>in)
    {
        auto mins = in.begin();
        int index = 0;
        for (int i = 1; i < in.size(); i++)
        {
            if(*mins > in[i])
            {
                mins = in.begin() + i; 
                index = i;
            }
            else if(*mins == in[i])
            {
                for (int j = 1; j < in.size(); j++)
                {
                    if(in[(index + j) % in.size()] > in[(i + j)%in.size()])
                    {
                        index = i;
                        break;
                    }
                    else if(in[(index + j) % in.size()] < in[(i + j)%in.size()]) 
                        break;
                }
            }
        }
        for (int i = 0; i < in.size(); i++)
        {
            cout<<in[(index + i) % in.size()];
        }
        cout<<endl;         
    }
}