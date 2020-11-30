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
ll n, m, p, k;
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
    input(n, m, k, p);
    ll ans = min(m, k/p);
    if((k - ans * p) > (ans-1) * (n-p)){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(ri i = 0; i < p; i++) cout << ans << ' ' << m - ans << endl, k -= ans;
    for(ri i = p; i < n; i++){
		if(k < ans) cout << k << ' ' << m - k << endl, k=0;
		else cout << ans - 1 << ' ' << m + 1 - ans << endl, k -= ans - 1;
	}
	return 0;
}