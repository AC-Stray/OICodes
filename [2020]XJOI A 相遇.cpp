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
ll t, k, v1, v2, x;
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
    input(t);
    while(t--){
        input(k, v1, v2, x);
		double firstMeet = x * (double)v1 / (v1 + v2);
        if(k == 1) printf("%.6lf\n", firstMeet);
		else if(v1 <= v2){
			if(k % 2 == 1) printf("%.6lf\n", firstMeet);
			else printf("%.6f\n", 200 * (double)v1 / (v1 + v2) - firstMeet);
		}
		else while(true){
			if(firstMeet + 2 * firstMeet / (double)(v1 - v2) * v2 > 100){
				if(k % 2 == 1) printf("%.6lf\n", firstMeet);
				else printf("%.6f\n", 200 * (double)v1 / (v1 + v2) - firstMeet);
				break;
			}
			else{
				k--;
				if(k == 0) { printf("%.6f\n", firstMeet); break; }
				firstMeet += 2 * firstMeet / (double)(v1 - v2) * v2;
			}
		}
    }
	return 0;
}