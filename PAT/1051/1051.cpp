#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int M,N,K,x;
int main()
{
    cin>>M>>N>>K;
    while (K--)
    {
        stack<int> st;
        vector<int> check;
        for (int i = 0; i < N; i++)
        {
            cin>>x;
            check.push_back(x);
        }
        bool flag = true;
        int index = 0;
        for (int i = 1; i <= N ; i++)
        {
            st.push(i);
            if(st.size() > M) 
            {
                flag = false;
                break;
            }
            while (!st.empty() && st.top() == check[index])
            {
                st.pop();
                index++;
            }
        }
        if(!st.empty() || index != check.size()) flag = false;
        printf("%s\n", flag==true?"YES":"NO");
    }
    
}