#include<iostream>
#include<math.h>
using namespace std;

// 转化为数
long long int dec(string n, int r)
{
    long long int deci = 0; 
    // 需要使用快速幂
    for (int i = 0; i < n.length() ; i++)
    {
        char t = n[i];
        if(t <= '9') deci = deci * r + (t - '0');
        else if(t <= 'z') deci = deci * r + ( t - 'a' + 10) ;
    }
    return deci;
}
// 找到最小的基数
long long getMinRadix(string num)
{
    char max = '0';
    for (int i = 0; i < num.length(); i++)
        if(num[i] > max) max = num[i];
    if(max <= '9') return max - '0' + 1;
    else return max - 'a' + 10; 
    
}
// 采用二分查找
long long getRadix(long long num1, string num2, long long start , long long end)
{
    if(start == end){
        if(dec(num2, start) == num1) return start;
        else return 0;
    }
    else if(start < end)
    {
        long long int r = (start + end) / 2;
        if(dec(num2, r) == num1) return r;
        else if(dec(num2, r) > num1 || dec(num2, r) < 0) return getRadix(num1, num2, start, r - 1);
        else return getRadix(num1, num2, r + 1, end);
    }
    return 0;
}

int main()
{
    string n1,n2;
    int N,radix;
    cin>>n1>>n2>>N>>radix;
    long long int a;
    string b;
    if(N == 1)
    {
        a = dec(n1, radix);
        b = n2;
    }
    else if (N == 2)
    {
        a = dec(n2, radix);
        b = n1;
    }
    if( a == 0 && b == "0"){//试了一下，测试用例没有这种情况
        cout<<"2";
        return 0;
    }

    auto res = getRadix(a, b, getMinRadix(b), a+1);
    if(res != 0) cout<<res;
    else cout<<"Impossible";
    return 0;
    
}
//注意例子 1 1 1 10