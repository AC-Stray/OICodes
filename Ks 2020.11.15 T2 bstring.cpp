#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int tmp, k, p, q, ans;
string s, t;
vector<int>sub;
int main(){
    freopen("input.in", "r", stdin);
    cin >> tmp >> tmp >> k;
    cin >> s >> t;
    if(s.size() < t.size()) swap(s, t);
    while(p < s.size()){
        for(int i = q; i < t.size(); i++)
            for(int j = 0; j+p < s.size() && j+i < t.size(); j++)
                if(j != 0 && s[j+p] != t[j+i]){
                    sub.push_back(j);
                    p += j;
                    q = i + j + 1;
                }
        p++;
    }
    sort(sub.begin(), sub.end());
    for(int i = sub.size() - k; i < sub.size(); i++) ans += sub[i];
    cout << ans;
    return 0;
}