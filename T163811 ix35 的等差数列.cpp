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
int n, w, ans, maxv, cnt[300005], a[300005];
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
    ans = 0x7fffffff;
    input(n, w);
    for(ri i = 0; i < n; i++) input(a[i]);
    for(ri d = 0; a[0] + d*(n-1) <= w; d++){
        memset(cnt, 0, sizeof(cnt));
        maxv = -1;
        for(ri i = 0; i < n; i++) if(a[i]-d*i >= 0) cnt[maxv = max(maxv, a[i]-d*i), a[i]-d*i]++;
        for(ri i = 0; i <= maxv; i++) ans = min(ans, n - cnt[i]);
        if(ans == 0) break;
    }
    cout << ans;
    return 0;
}