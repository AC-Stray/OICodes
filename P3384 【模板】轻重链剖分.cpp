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
int n, m, r, p, initv[100005], v[100005];
int cnt, son[100005], fa[100005], dep[100005], siz[100005], top[100005], dfn[100005];
vector<int> g[100005];
struct node{
    int l, r, v, add;
};
struct segtree{
    node t[400005];
    #define ls t[p<<1]
    #define rs t[p<<1|1]
    void pushup(int p) { t[p].v = ls.v + rs.v; }
    void pushdown(int p){
        if(t[p].add){
            ls.v += (ls.r - ls.l + 1) * t[p].add;
            ls.add += t[p].add;
            rs.v += (rs.r - rs.l + 1) * t[p].add;
            rs.add += t[p].add;
            t[p].add = 0;
        }
    }
    void build(int p, int l, int r){
        t[p].l = l;
        t[p].r = r;
        if(l == r){
            t[p].v = v[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p<<1, l, mid);
        build(p<<1|1, mid+1, r);
        pushup(p);
    }
    int query(int p, int l, int r){
        if(t[p].l >= l && t[p].r <= r) return t[p].v;
        pushdown(p);
        int res = 0, mid = (l + r) >> 1;
        if(mid >= l) res += query(p<<1, l, r);
        if(mid < r) res += query(p<<1|1, l, r);
    }
    void update(int p, int l, int r, int k){
        if(t[p].l >= l && t[p].r <= r){
            t[p].add += k;
            t[p].v = (t[p].r - t[p].l + 1) * k;
            return;
        }
        pushdown(p);
        int mid = (l + r) >> 1;
        if(mid >= l) update(p<<1, l, r, k);
        if(mid < r) update(p<<1|1, l, r, k);
        pushup(p);
    }
    #undef ls
    #undef rs
}TREE;
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
void dfs1(int p, int f){
    son[p] = -1;
    siz[p] = 1;
    for(ri i = 0; i < g[p].size(); i++){
        int v = g[p][i];
        if(v == f) continue;
        dep[v] = dep[p] + 1;
        fa[v] = p;
        dfs1(v, p);
        siz[p] += siz[v];
        if(son[p] == -1 || siz[v] > siz[son[p]]) son[p] = v;
    }
}
void dfs2(int p, int s){
    top[p] = s;
    dfn[p] = ++cnt;
    if(son[p] == -1) return;
    dfs2(son[p], s);
    for(ri i = 0; i < g[p].size(); i++){
        int v = g[p][i];
        if(v == fa[p] || v == son[p]) continue;
        dfs2(v, v);
    }
}
int queryPath(int x, int y){
    int res = 0;
    while(x[top] != y[top]){
        if(x[top][dep] < y[top][dep]) swap(x, y);
        res = (res + TREE.query(1, x[top][dfn], x[dfn])) % p;
        x = x[top];
    }
    res = (res + TREE.query(1, x[dfn], y[dfn])) % p;
    return res;
}
void updatePath(int x, int y, int k){
    while(x[top] != y[top]){
        if(x[top][dep] < y[top][dep]) swap(x, y);
        TREE.update(1, x[top][dfn], x[dfn], k);
        x = x[top];
    }
    TREE.update(1, x[dfn], y[dfn], k);
}
int main(){
    input(n, m, r, p);
    for(ri i = 1; i <= n; i++) input(initv[i]);
    for(ri i = 1; i < n; i++){
        int u, v;
        input(u, v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(r, 0);
    dfs2(r, r);
    for(ri i = 1; i <= n; i++) v[dfn[i]] = initv[i];
    TREE.build(1, 1, n);
    while(m--){
        int op, x, y, z;
        input(op);
        switch(op){
            case 1:
                input(x, y, z);
                updatePath(x, y, z);
            case 2:
                input(x, y);
                cout << queryPath(x, y) << endl;
            case 3:
                input(x, z);
                TREE.update(1, x[dfn], x[dfn] + x[siz], z);
            case 4:
                input(x);
                cout << TREE.query(1, x[dfn], x[dfn] + x[siz]) << endl;
        }
    }
    return 0;
}