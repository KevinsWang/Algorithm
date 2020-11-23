#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int N; // <=30
int post[32], in[32];


struct node
{
    int data;
    node * l;
    node * r;
};

node * create(int postl, int postr, int inl, int inr)
{
    if(postl > postr) return NULL;

    node * root = new node;
    root->data = post[postr];
    int i;
    for (i = inl; i <= inr ; i++)
    {
        if(in[i] == post[postr]) break;
    }
    int leftnum = i - inl;

    root->l = create(postl, postl + leftnum - 1, inl, inl + leftnum - 1);
    root->r = create(postl + leftnum, postr - 1, i + 1, inr);
    return root;
}

void levelOrder(node * root)
{
    queue<node *> q;
    q.push(root);
    node * t;
    while (!q.empty())
    {
        t = q.front();
        q.pop();
        printf("%d", t->data);
        if(t->l) q.push(t->l);
        if(t->r) q.push(t->r);
        if(q.empty()) break;
        printf(" ");
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &post[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &in[i]);
    node * root;
    root = create(0, N-1, 0, N-1);
    levelOrder(root);
    cout<<endl;
}