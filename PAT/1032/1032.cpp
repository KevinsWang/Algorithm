#include<iostream>
using namespace std;

struct 
{
    char key;
    int next;
    bool flag;
}node[100002];

int main()
{
    int b1,b2,N;
    scanf("%d%d%d", &b1,&b2,&N);
    for (int i = 0; i < N; i++)
    {
        int x,y;
        char z;
        scanf("%d %c %d", &x,&z,&y);
        node[x] = {z, y, false};
    }
    for (int i = b1; i != -1; i = node[i].next)
        node[i].flag = true;
    for (int i = b2; i != -1; i = node[i].next)
        if(node[i].flag == true) 
        {
            printf("%05d", i);
            return 0;
        }
    
    printf("-1");
    return 0;
}