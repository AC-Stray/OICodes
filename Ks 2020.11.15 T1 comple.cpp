#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
using namespace std;
map<string, int>s;
int tw, w, ans;
string tmp, name, d;
int main(){
    freopen("input.in", "r", stdin);
    s["i"] = 0;
    while(cin >> tmp){
        if(tmp == "S"){
            w = 0;
            cin >> name >> tmp;
            while(tmp != "E"){
                cin >> d;
                tw = 0;
                for(int i = 0; i < d.size(); i++)
                    if(d[i] == 'n') tw++;
                w = max(w, s[tmp] + tw);
                cin >> tmp;
            }
            s[name] = w;
        }
    }
    for(map<string, int>::iterator iter = s.begin(); iter != s.end(); iter++)
        ans = max(ans, iter->second);
    if(ans == 0) cout << "O(1)";
    else if(ans == 1) cout << "O(n)";
    else cout << "O(n^" << ans << ")";
    return 0;
}