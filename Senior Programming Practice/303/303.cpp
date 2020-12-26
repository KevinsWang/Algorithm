#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int mv[8][2] = {
     1, 0,
     1, 1,
     0, 1,
    -1, 1,
    -1, 0,
    -1,-1,
     0,-1,
     1,-1
};

int main()
{
    for (int i = 0; i < 8; i++)
    {
        cout<<mv[i][0]<<" "<<mv[i][1]<<endl;
    }
      
}
