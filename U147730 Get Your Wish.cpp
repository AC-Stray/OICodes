#include<bits/stdc++.h>
#define File(name) freopen(name".in", "r", stdin); freopen(name".out", "w", stdout);
#define Int inline int
#define Void inline void
#define Bool inline bool
#define DB inline double
#define LL inline long long
#define ri register int
#define re register
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
int n, m, mvx, mvy;
char g, mp[105][105];
LL read(){
    ll n = 0; int f = 1; char ch = getchar();
    while('0' > ch || ch > '9'){
        if(ch == '-') f *= -1;
        ch = getchar();
    }
    while('0' <= ch && ch <= '9'){
        n = (n << 1) + (n << 3) + ch-'0';
        ch = getchar();
    }
    return f * n;
}
Void write(ll x){
    if(x/10) write(x/10);
    putchar(x%10+'0');
}
Void input() {}
template<typename Type, typename... Types>
Void input(Type& arg, Types&... args){
    arg = read();
    input(args...);
}
int main(){
    input(n, m);
    cin >> g;
    switch(g){
        case '<': mvx = 0, mvy = -1; break;
        case '^': mvx = -1, mvy = 0; break;
        case '>': mvx = 0, mvy = 1; break;
        case 'v': mvx = 1, mvy = 0; break;
    }
    for(ri i = 0; i < n; i++) for(ri j = 0; j < m; j++) cin >> mp[i][j];
    for(ri i = 0; i < n; i++) for(ri j = 0; j < m; j++){
        if(mp[i][j] != 'o') continue;
        int nx = i + mvx, ny = j + mvy;
        while(nx >= 0 && nx < n && ny >= 0 && ny < m){
            if(mp[nx][ny] == 'x'){
                puts("GG");
                return 0;
            }
            nx += mvx, ny += mvy;
        }
    }
    puts("OK");
    return 0;
}