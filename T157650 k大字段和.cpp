#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<vector>
#include<set>
#include<queue>
#include<string>
#include<cstring>
#include<map>
#include<list>
#include<deque>
#include<cctype>
#include<climits>
#include<cmath>
#include<ctime>
#include<algorithm>
#define File(name) freopen(name".in", "r", stdin); freopen(name".out", "w", stdout);
#define Int inline int
#define Void inline void
#define Bool inline bool
#define DB inline double
#define LL inline long long
#define ri register int
#define re register
#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
int n, k, len, cnt, l, r, ans, a[100005], b[100005], sum[100005], tree[200005];
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
Int lowbit(int x){
    return x & -x;
}
Void add(int x, int y){
    for(ri i = x; i <= len; i += lowbit(i)) tree[i] += y;
}
Int query(int x){
    int sum = 0;
    for(ri i = x; i > 0; i -= lowbit(i)) sum += tree[i];
    return sum;
}
Bool check(int mid){
    memset(tree, 0, sizeof(tree));
    for(ri i = 1; i <= n; i++){
        int x = sum[i] - mid;
        int p = lower_bound(b+1, b+len+1, x) - b - 1;
        cnt += query(p);
        if(x > 0) cnt++;
        p = lower_bound(b+1, b+len+1, sum[i]) - b;
        add(p, 1);
    }
    return cnt >= k;
}
signed main(){
    input(n, k);
    for(ri i = 1; i <= n; i++){
        input(a[i]);
        b[i] = sum[i] = sum[i-1] + a[i];
    }
    sort(b+1, b+n+1);
    len = unique(b+1, b+n+1) - b - 1;
    l = -0x3f3f3f3f3f3f, r = 0x3f3f3f3f3f3f;
    while(l <= r){
        cnt = 0;
        int mid = (l + r) / 2;
        if(check(mid)) l = mid + 1;
        else r = mid - 1, ans = mid;
    }
    cout << ans;
	return 0;
}