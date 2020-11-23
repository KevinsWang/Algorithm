#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node
{
    int layer;
    vector<int> child;
}Node[105];


void ANS(int a)
{   
    queue<int> Q;
    Q.push(a);
    int layer = Node[a].layer;
    int count = 0;
    while (!Q.empty())
    {
        int front = Q.front();
        Q.pop();
        if(Node[front].layer != layer)   // 到下一层了
        {
            cout<<count<<" ";
            count = 0;
            layer = Node[front].layer;
        }
        if(Node[front].child.size() == 0) count++;
        else
        {
            for (int i = 0; i < Node[front].child.size(); i++)
            {
                Q.push(Node[front].child[i]);
            }
            
        }
         
    }
    cout<<count;
}


int main()
{
    int N,M;        // 节点数，非叶子节点数
    cin>>N>>M;
    
    Node[1].layer = 1;  // 初始化根节点的层数
    for (int i = 0; i < M; i++)
    {
        int id,k,tmp;
        cin>>id>>k;
        for (int j = 0; j < k; j++)
        {
            cin>>tmp;
            Node[id].child.push_back(tmp);
            Node[tmp].layer = Node[id].layer + 1;
        }
    }
    ANS(1);
    return 0;
}
/**
2 1
01 1 02 
 */