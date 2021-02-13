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
const int MOD = 998244353;
ll n, sum, all, ans;
string str;
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
LL qpow(int a, int k){
    ll res = 1, x = a;
    while(k > 0){
        if(k & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        k >>= 1;
    }
    return res;
}
int main(){
    input(n);
    cin >> str;
    ans = 1;
    for(ri i = 0; i < str.size(); i++){
        sum += str[i] == '(' ? 1 : -1;
        if(sum == 0) ans *= 2;
    }
    all = 1;
    for(ri i = 2 * n; i > n; i--) all = (all * i) % MOD;
    for(ri i = n; i > 0; i--) all = (all * qpow(i, MOD-2)) % MOD;
    // cout << ans << ' ' << all << endl;
    cout << (ans*qpow(all, MOD-2))%MOD;
    return 0;
}