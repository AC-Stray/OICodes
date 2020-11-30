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
string out;
char ch;
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
inline char translate(char ch){
    switch(ch){
        case '0': return 'F';
        case '1': return 'E';
        case '2': return 'D';
        case '3': return 'C';
        case '4': return 'B';
        case '5': return 'A';
        case '6': return '9';
        case '7': return '8';
        case '8': return '7';
        case '9': return '6';
        case 'A': return '5';
        case 'B': return '4';
        case 'C': return '3';
        case 'D': return '2';
        case 'E': return '1';
        case 'F': return '0';
    }
}
int main(){
    out = "#";
    getchar();
    for(ri i = 0; i < 6; i++) out.push_back(translate(getchar()));
    cout << out;
	return 0;
}