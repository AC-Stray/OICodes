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
int t, m;
bool flag;
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
Void solve(int n, char ch){
	int tmp = (-1 + sqrt(1 + 8*n)) / 2;
	for(ri i = 1; i <= tmp; i++) cout << ch;
	n -= (tmp * tmp + tmp) / 2;
	if(n != 0) solve(n, ch+1);
}
int main(){
    input(t);
    while(t--){
        input(m);
		solve(m, 'a');
		cout << endl;
    }
	return 0;
}