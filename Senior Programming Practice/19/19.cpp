#include<iostream>
#include<map>
#include<iomanip>
#include<string>
using namespace std;

map<string, int> m;

void coutInt(int x)
{
    cout<<"|";
    if(x == 0) cout<<"     |";
    else
        cout<<"  "<<x<<"  |";
}

void coutStr(string str)
{
    int len;
    if(str.empty()) cout<<setfill(' ')<<setw(12)<<right<<"|";
    else
    {
        len = (11 - str.size()) / 2;
        cout<<setfill(' ')<<setw(len)<<' ';
        cout<<setfill(' ')<<setw(11 - len)<<left<<str;
        cout<<'|';
    } 
      
}

void coutTitle()
{
    cout<<"+-----+";
    for (int i = 0; i < 5; i++) 
        cout<<setfill('-')<<setw(12)<<right<<"+";
    cout<<endl;
}

int main()
{
    m["MON"] = 0;
    m["TUE"] = 1;
    m["WED"] = 2;
    m["THU"] = 3;
    m["FRI"] = 4;
    m["Morning"] = 0;
    m["Afternoon"] = 1;
    int n, course;  //course is needed to subtract 1
    string x,y;
    int z;
    while (cin>>n)
    {
        string table[4][5][2];
        getchar();
        for (int i = 0; i < n; i++)
        {
            string line;
            
            getline(cin,line);
            int index = line.find(":");
            x = line.substr(index + 2, 3);
            y = line.substr(index + 6, line.size() - index - 8);
            z = atoi(line.substr(line.size() - 1, 1).c_str());
            table[z - 1][m[x]][m[y]] = line.substr(0, index);
        }
        coutTitle();
        coutInt(0);
        coutStr("MON");
        coutStr("TUE");
        coutStr("WED");
        coutStr("THU");
        coutStr("FRI");
        cout<<endl;
        coutTitle();
        cout<<"|";
        cout<<setfill(' ')<<setw(26)<<' ';
        cout<<setfill(' ')<<setw(39)<<left<<"Morning";
        cout<<"|"<<endl;
        coutTitle();
        for (int j = 1; j < 5; j++)
        {
            coutInt(j);
            for (int i = 0; i < 5; i++) coutStr(table[j - 1][i][0]);
            cout<<endl;
            coutTitle();    
        }
        cout<<"|";
        cout<<setfill(' ')<<setw(25)<<' ';
        cout<<setfill(' ')<<setw(40)<<left<<"Afternoon";
        cout<<"|"<<endl;
        coutTitle();
        for (int j = 1; j < 4; j++)
        {
            coutInt(j);
            for (int i = 0; i < 5; i++) coutStr(table[j - 1][i][1]);
            cout<<endl;
            coutTitle();    
        }

        cout<<endl;
    }
    
}
