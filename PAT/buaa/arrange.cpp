#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int a[102], t[102]; // a是输入的数据数组，t是输出的数组
int N;              // 数据个数

int findRoot(int num)
{
    int n = log(num + 1) / log(2);     // 层数
    int len = num - pow(2, n) + 1;     // 左子数中多的个数
    if((double)len > pow(2, n - 1)) len = pow(2, n - 1);    // 超过一半时
    return pow(2, n-1) - 1 + len;
}

void convert(int root, int index, int left, int right)
{
    if(left > right) return;
    t[index] = a[root];
    convert(left+findRoot(root - left), index * 2 + 1, left, root - 1);
    convert(root+1+findRoot(right - root), index * 2 + 2, root + 1, right);
}

int main()
{
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
    }
    sort(a, a + N);
    //for (int i = 0; i < N; i++) cout<<a[i]<< " ";
    //cout<<findRoot(18);
    convert(findRoot(N), 0, 0, N - 1 );
    for (int i = 0; i < N; i++)
    {
        cout<<t[i]<<" ";
    }
    return 0;
}