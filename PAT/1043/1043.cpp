#include<iostream>
#include<vector>
using namespace std;
struct node
{
    int data;
    node * l;
    node * r;
};
vector<int> postans;
int key[1002];

void postOrder( node * root)
{
    if(root == NULL) return;
    postOrder(root->l);
    postOrder(root->r);
    postans.push_back(root->data);
}
// 左小右大
node * BSTcreate(int left, int right, bool & flag)
{
    if(flag == true) return NULL;
    if(left > right) return NULL;

    node * root = new node;
    root->data = key[left];
    int i,j;
    for (i = left + 1; i <= right && key[i] < key[left] ; i++);
    for (j = i; j <= right && key[j] >= key[left] ; j++);

    if(j <= right)
    {
        flag = true;
        return NULL;
    }
    
    root->l = BSTcreate(left + 1, i -1, flag);
    root->r = BSTcreate(i, right, flag);
    return root;
}

node * MBSTcreate(int left, int right, bool & flag)
{
    if(flag == true) return NULL;
    if(left > right) return NULL;

    node * root = new node;
    root->data = key[left];
    int i,j;
    for (i = left + 1; i <= right && key[i] >= key[left] ; i++);
    for (j = i; j <= right && key[j] < key[left] ; j++);

    if(j <= right)
    {
        flag = true;
        return NULL;
    }
    
    root->l = MBSTcreate(left + 1, i -1, flag);
    root->r = MBSTcreate(i, right, flag);
    return root;
}

int main()
{
    int N;
    bool flag = false;
    cin>>N;
    
    for (int i = 0; i < N; i++)
        cin>>key[i];
    
    node * root;
    if(key[1] < key[0]) root = BSTcreate(0, N - 1, flag);
    else if( key[1] >= key[0] ) root = MBSTcreate(0, N - 1, flag);

    if(flag == true) cout<<"NO"<<endl;
    else 
    {
        cout<<"YES"<<endl;
        postOrder(root);
        cout<<postans[0];
        for (int i = 1; i < postans.size(); i++)
            cout<<" "<<postans[i];
        
    }
}