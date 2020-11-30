#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define File(name) freopen(name".in", "r", stdin); freopen(name".out", "w", stdout);
#define Int inline int
#define Void inline void
#define Bool inline bool
#define LL inline long long
#define DB inline double
#define ri register int
#define re register
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
int n, a[4000005];
__int128_t now, ans;
Void write(__int128_t n){
	if(n / 10) write(n / 10);
	putchar(n%10+'0');
}
LL read(){
	ll n = 0; int f = 1; char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') f *= -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		n = n * 10 + ch-'0';
		ch = getchar();
	}
	return f * n;
}
Void input() {}
template<typename Type, typename... Types>
Void input(Type& arg, Types&... args){
	arg = read();
	input(args...);
}
int main(){
	input(n);
	for(ri i = 0; i < n; i++) input(a[i]);
	now = a[0];
	for(ri i = 1; i < n; i++){
		ans += now * a[i];
		now += a[i];
	}
	write(ans);
	return 0;
}
