#include<iostream>

using namespace std;

/**
 * @brief 可能出现
 * 2 4
 * 1 0 0 0
 * 0 1 1 1
 * 2
 * 的情况，此算法欠考虑
 * @return int 
 */
// int main()
// {
//     int n,m,mixmal;
//     while (cin>>n)
//     {
//         cin>>m;
//         int like[n][m];
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < m; j++)
//                 cin>>like[i][j];   
//         cin>>mixmal;
//         if(mixmal * n < m){
//             cout<<"No"<<endl;
//             continue;
//         }
//         bool flag = true;
//         for (int i = 0; i < m; i++)
//         {
//             int test = 0;
//             for (int j = 0; j < n; j++)
//             {
//                 test |= like[j][i];
//             }
//             if(test == 0) 
//             {
//                 flag = false;
//                 break;
//             }
//         }
//         cout<< (flag ? "Yes" : "No" )<<endl;
//     }
    
// }

/**
 * @brief 要用到贪心的思想 
 * 
 * @return int 
 */
int main()
{
    int n,m,k;
    while (cin>>n)
    {
        cin>>m;
        int like[n][m + 1];
        int rest[n];
        double weight[n][m];
        for (int i = 0; i < n; i++)
        {    
            like[i][m] = 0;
            for (int j = 0; j < m; j++)
            {
                cin>>like[i][j];
                like[i][m] += like[i][j];
            }
        }
        cin>>k;
        for (int i = 0; i < n; i++) rest[i] = k;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                weight[i][j] = 1.0 * like[i][j] / like[i][m];
        int flag = 1;
        for (int i = 0; i < m && flag; i++)
        {
            double maxw = 0;
            int maxid, flag2 = 0;
            for (int j = 0; j < n; j++)
                if(weight[j][i] > maxw && rest[j] > 0)
                {
                    maxw = weight[j][i];
                    maxid = j;
                    flag2 = 1;
                }
            if(flag2) rest[maxid]-- ;
            else flag = 0;
        }
        cout<<(flag == 1 ? "Yes" : "No")<<endl;
    }
}