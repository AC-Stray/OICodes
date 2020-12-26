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
int now, n, value, ans, maping[26], mapNum[3];
bool cannot[26][10], use[26];
string str, num[3];
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
Void dfs(int ch){
	int nxt = -1;
	for(ri i = ch + 1; i < 26; i++) if(use[i]){
		nxt = i;
		break;
	}
	for(ri i = 0; i < 10; i++){
		if(cannot[ch][i]) continue;
		maping[ch] = i;
		if(nxt == -1){
			for(ri i = 0; i < 3; i++){
				mapNum[i] = 0;
				for(ri j = 0; j < num[i].size(); j++) mapNum[i] = mapNum[i] * 10 + maping[num[i][j]-'A'];
			}
			if(mapNum[0] + mapNum[1] == mapNum[2]) ans++;
		}
		else dfs(nxt);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> str;
	for(ri i = 0; i < str.size(); i++){
		if(str[i] == '+' || str[i] == '=') now++;
		else{
			num[now].push_back(str[i]);
			use[str[i]-'A'] = true;
		}
	}
	cin >> n;
	for(ri i = 0; i < n; i++){
		cin >> ch >> value;
		cannot[ch-'A'][value] = true;
	}
	for(ri i = 0; i < 3; i++)
		cannot[num[i][0]-'A'][0] = true;
	for(ri i = 0; i < n; i++) if(use[i]){
		dfs(i);
		break;
	}
	cout << ans;
	return 0;
}