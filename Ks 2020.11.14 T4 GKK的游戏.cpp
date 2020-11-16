#include<cstdio>
#include<queue>
using namespace std;
int n, m, fa[200005];
unsigned long long ans;
struct node{
    int u, v, w;
    node() {}
    node(int u, int v, int w): u(u), v(v), w(w) {}
    node next(){
        return node((u+1)%n, (v+1)%n, w+2);
    }
    bool operator < (const node &b) const{
        return w > b.w;
    }
}tmp;
priority_queue<node>q;
int get(int x){
    return (fa[x] == x) ? x : (fa[x] = get(fa[x]));
}
void unite(int x, int y){
    fa[get(x)] = get(y);
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &tmp.u, &tmp.v, &tmp.w);
        q.push(tmp);
        q.push(node(tmp.v, tmp.u+1, tmp.w+1));
    }
    for(int i = 0; i < n; i++) fa[i] = i;
    while(!q.empty()){
        node now = q.top();
        q.pop();
        if(get(now.u) == get(now.v)) continue;
        unite(now.u, now.v);
        ans += now.w;
        q.push(now.next());
    }
    printf("%llu", ans);
    return 0;
}