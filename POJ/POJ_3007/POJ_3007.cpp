/*
本题字典树使用大量空间来换取时间，在内存允许的范围内将效率提高
字典树真香
这个算法巧妙地减少了时间、空间的浪费，tql
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

//字典书，用于判断两个字符串书否重复
struct node
{
    int flag, next[26];
} p[100086];
int ans, top;

//因为需要重复使用字典树n次，所以需要有个清空记录的函数（就不需要创新创建结构了），不然可以直接创建一个初始值全为零的p
void create(int x)
{
    p[x].flag = 0;
    for (int i = 0; i < 26; i++)
        p[x].next[i] = -1;
}

void add(int x, char *s, int l)
{
    for (int i = 0; i < l; i++)
    {
        /*------------核心代码--------------*/
        if (p[x].next[s[i] - 'a'] < 0)
        {
            //top是全局变量，是在一次while中只会增加不会减少的
            p[x].next[s[i] - 'a'] = top;
            create(top++);
        }
        x = p[x].next[s[i] - 'a'];
        /*---------------------------------*/
    }
    if (!p[x].flag)
    {
        p[x].flag = 1;
        ans++;
    }
}

int main()
{
    int t, l, i, j, k, q;
    char s[128], s1[128], s2[128];
    cin>>t;
    while (t--)
    {
        //每判断一个字符串都会从新开始
        top = ans = 0;              
        create(top++);
        cin>>s;
        l = (int)strlen(s);
        for (i = 0; i < l; i++) 
        //因为是从i=0开始的，所以已经考虑过的1正，2正，1+2和1反，2反，2+1的情况，所以下面只用考虑其他6种
        {
            //1正i,2正l-i，2+1
            k = q = 0;
            for (j = 0; j < i; j++)
                s1[k++] = s[j];
            for (j = i; j < l; j++)
                s2[q++] = s[j];
            s1[k++] = s2[q++] = 0;      //存入'\0'，将上一个循环的s2最后一个值给覆盖了，这样就不会出现脏数据
            strcat(s2, s1);
            add(0, s2, (int)strlen(s2));
            
            //1反i,2正l-i，1+2
            k = q = 0;
            for (j = i - 1; j >= 0; j--)
                s1[k++] = s[j];
            for (j = i; j < l; j++)
                s2[q++] = s[j];
            s1[k++] = s2[q++] = 0;
            strcat(s1, s2);
            add(0, s1, (int)strlen(s1));
            
            //1反i,2正l-i，2+1
            k = q = 0;
            for (j = i - 1; j >= 0; j--)
                s1[k++] = s[j];
            for (j = i; j < l; j++)
                s2[q++] = s[j];
            s1[k++] = s2[q++] = 0;
            strcat(s2, s1);
            add(0, s2, (int)strlen(s2));
            
            //1正2反，1+2
            k = q = 0;
            for (j = 0; j < i; j++)
                s1[k++] = s[j];
            for (j = l - 1; j >= i; j--)
                s2[q++] = s[j];
            s1[k++] = s2[q++] = 0;
            strcat(s1, s2);
            add(0, s1, (int)strlen(s1));
            
            //1正2反，2+1
            k = q = 0;
            for (j = 0; j < i; j++)
                s1[k++] = s[j];
            for (j = l - 1; j >= i; j--)
                s2[q++] = s[j];
            s1[k++] = s2[q++] = 0;
            strcat(s2, s1);
            add(0, s2, (int)strlen(s2));
            
            //1反2反，1+2
            k = q = 0;
            for (j = i - 1; j >= 0; j--)
                s1[k++] = s[j];
            for (j = l - 1; j >= i; j--)
                s2[q++] = s[j];
            s1[k++] = s2[q++] = 0;
            strcat(s1, s2);
            add(0, s1, (int)strlen(s1));
        }
        //printf("%d\n", ans);
        cout<<ans<<endl;
    }
    return 0;
}

/*
sample input:
4
aa
abba
abcd
abcde
*/
