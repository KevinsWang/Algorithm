#include<iostream>
#include<set>
using namespace std;
int main(){
    int T,n,ans,x;
    cin>>T;
    while (T--){
        ans = 0;
        cin>>n;
        set<int> line[n + 1];        
        for (int i = 0; i < n; i++){
            cin>>x;
            for (int j = 0; j <= ans ; j++){
                if(line[j].find(x) == line[j].end()){
                    if(line[j].empty()) ans++;
                    line[j].insert(x);
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
}