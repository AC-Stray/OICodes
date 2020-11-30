#include<bits/stdc++.h>
#define File(name) freopen(name".in", "r", stdin); freopen(name".out", "w", stdout);
#define Int inline int
#define Void inline void
#define Bool inline bool
#define Char inline char
#define LL inline long long
#define DB inline double
#define ri register int
#define re register
using namespace std; 
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
int t;
struct node{
    int now;
    int times;
    node() {}
    node(int now, int times): now(now), times(times) {}
};
queue<node> q;
int n[4];
bool vis[1 << 16];
LL read(){
    ll n = 0; int f = 1; char ch = getchar();
    while(!isdigit(ch)){
        if(ch == '-') f *= -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        n = (n << 1) + (n << 3) + ch-'0';
        ch = getchar();
    }
    return f * n;
}
Void write(ll n){
    if(n/10) write(n/10);
    putchar(n%10+'0');
}
int main(){
//	File("chess")
    freopen("input.in", "r", stdin);
    t = read();
    while(t--){
        memset(n, 0, sizeof(n));
        memset(vis, 0, sizeof(vis));
        for(ri i = 15; i >= 0; i--) n[read()-1] += (1 << i);
        for(ri i = 0; i < 4; i++) q.push(node(n[i], 0));
        while(!q.empty()){
            node now = q.front(), sv = now;
            bool mp[4][4];
            q.pop();
            vis[now.now] = true;
            for(ri i = 3; i >= 0; i--) for(ri j = 3; j >= 0; j--) mp[i][j] = now.now & 1, now.now >>= 1;
            bool flag = false;
            for(ri i = 0; i < 3; i++) for(ri j = 0; j < 3; j++){
                if(mp[i][j] && mp[i+1][j] && mp[i][j+1] && mp[i+1][j+1]){
                    write(now.times);
                    puts("");
                    while(!q.empty()) q.pop();
                    flag = true;
                    break;
                }
                if(flag) break;
            }
            if(flag) break;
            for(ri i = 0; i < 4; i++){ // >
                now = sv;
                for(ri j = 0; j < 4; j++)
                    now.now += (mp[i][j==3?0:j+1]-mp[i][j]) * (1 << (15-4*i-j));
                if(!vis[now.now]) q.push(node(now.now, now.times+1));
            }
            for(ri i = 0; i < 4; i++){ // ^
                now = sv;
                for(ri j = 0; j < 4; j++)
                    now.now += (mp[j==3?0:j+1][i]-mp[j][i]) * (1 << (15-4*j-i));
                if(!vis[now.now]) q.push(node(now.now, now.times+1));
            }
        }
    }
    return 0;
}
/*
1 
1 2 1 2 
1 3 4 2 
3 1 2 4 
3 4 3 4 
=======
4
*/