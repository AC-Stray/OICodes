#include<bits/stdc++.h>
using namespace std;
struct edge{
	int i, j, w;
	edge() {}
	edge(int i, int j, int w): i(i), j(j), w(w) {}
};
int t, n, m, s, p, q, r, ans, w[505][505], fa[505];
bool g[505][505];
bool flag;
inline int get(int x){
	if(fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}
inline void unite(int x, int y){
	fa[get(x)] = get(y);
}
inline void dfs(int p, int d){
	ans = max(ans, d);
	if(ans >= s) flag = true;
	for(register int i = 0; i < n; i++){
		if(!g[p][i]) continue;
		g[p][i] = g[i][p] = false;
		dfs(i, d+w[p][i]);
		if(flag) return;
		g[p][i] = g[i][p] = true;
	}
}
int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0;
		flag = false;
		memset(g, 0, sizeof(g));
		scanf("%d%d%d", &n, &m, &s);
		for(register int i = 1; i <= n; i++) fa[i] = i;
		for(register int i = 0; i < m; i++){
			scanf("%d%d%d", &p, &q, &r);
			if(!flag){
				g[p][q] = g[q][p] = true;
				w[p][q] = w[q][p] = r;
				if(get(p) == get(q)){
					printf("YES\n");
					flag = true;
				}
				unite(p, q);
			}
		}
		if(flag) continue;
		flag = false;
		for(register int i = 1; i <= n; i++){
			dfs(i, 0);
			if(flag) break;
		}
		if(ans >= s) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
