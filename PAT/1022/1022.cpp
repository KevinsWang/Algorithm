#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<set>
using namespace std;
/**
 * @brief 不知名报错，经过搜索解答，发现用map会很方便
 * 
 */
// struct book
// {
//     char id[7];
//     string title;
//     string author;
//     string key;
//     string publisher;
//     // string year;
// };

// vector<book> line;
// int N,K;
// bool cmp(book x, book y)
// {
//     return strcmp(x.id, y.id) < 0;
// }

// int main()
// {
//     cin>>N;
//     for (int i = 0; i < N; i++)
//     {
//         book tmp;
//         cin>>tmp.id>>tmp.title>>tmp.author>>tmp.key>>tmp.publisher;
//         line.push_back(tmp);
//     }
//     sort(line.begin(),line.end());
//     cin>>K;
//     for (int i = 0; i < K; i++)
//     {
//         int no;
//         string query;
//         bool flag;
//         scanf("%d: %s", &no, query);
//         printf("%d: %s", no, query);
        
//         switch (no)
//         {
//         case 1:
//             flag = false;
//             for (int i = 0; i < line.size(); i++)
//                 if(line[i].title == query) 
//                 {
//                     printf("%s\n", line[i].id);
//                     flag = true;
//                 }
//             if(flag == false) printf("Not Found\n");
//             break;
//         case 2:
//             flag = false;
//             for (int i = 0; i < line.size(); i++)
//                 if(line[i].author == query) 
//                 {
//                     printf("%s\n", line[i].id);
//                     flag = true;
//                 }
//             if(flag == false) printf("Not Found\n");
//             break;
//         case 3:
//             flag = false;
//             for (int i = 0; i < line.size(); i++)
//                 if(line[i].key == query) 
//                 {
//                     printf("%s\n", line[i].id);
//                     flag = true;
//                 }
//             if(flag == false) printf("Not Found\n");
//             break;
//         case 4:
//             flag = false;
//             for (int i = 0; i < line.size(); i++)
//                 if(line[i].publisher == query) 
//                 {
//                     printf("%s\n", line[i].id);
//                     flag = true;
//                 }
//             if(flag == false) printf("Not Found\n");
//             break;
//         // case 5:
//         //     flag = false;
//         //     for (int i = 0; i < line.size(); i++)
//         //         if(line[i].year == query) 
//         //         {
//         //             printf("%s\n", line[i].id);
//         //             flag = true;
//         //         }
//         //     if(flag == false) printf("Not Found\n");
//         //     break;
//         default:
//             break;
//         }
//     }
    
// }

int main()
{
    unordered_map<string, set<string>> line;
    string id, title, author, key, publisher, year, k;
    int n,m;
    cin>>n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, id);
        getline(cin, title);
        line[title].insert(id);
        getline(cin, author);
        line[author].insert(id);
        while (cin>>k)      // 关键词有很多，根据每个关键词都能找到这本书
        {
            char c = getchar();
            line[k].insert(id);
            if(c == '\n') break;
        }
        getline(cin, publisher);
        line[publisher].insert(id);
        getline(cin, year);
        line[year].insert(id);
    }
    cin>> m;
    int num;
    getchar();
    while(m--)
    {
        getline(cin, k);
        num = k[0] - '0';
        k = k.substr(3);
        cout<<num<<": "<<k<<endl;
        if(line[k].size() == 0) cout<<"Not Found"<<endl;
        else
        {
            for(auto t: line[k]) cout<<t<<endl;
        }
        

    }
}