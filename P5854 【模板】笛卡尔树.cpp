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
ll n, p[10000005],  ls[10000005], rs[10000005], stk[10000005], top, k, L, R; 
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
    input(n);
    for(ri i = 1; i <= n; i++){
        input(p[i]);
        k = top;
        while(k && p[stk[k]] > p[i]) k--;
        if(k) rs[stk[k]] = i;
        if(k < top) ls[i] = stk[k+1];
        stk[++k] = i;
        top = k;
    }
    for(ri i = 1; i <= n; i++) L ^= i * (ls[i]+1), R ^= i * (rs[i]+1);
    cout << L << ' ' << R;
    return 0;
}