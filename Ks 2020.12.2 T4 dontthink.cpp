#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define File(name) freopen(name".in", "r", stdin); freopen(name".out", "w", stdout);
#define Int inline int
#define Void inline void
#define Bool inline bool
#define LL inline long long
#define DB inline double
#define ri register int
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
int t, n, now[20] = {1};
bool flag;
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
Void write(ll n){
    if(n/10) write(n/10);
    putchar(n%10+'0');
}
Void input() {}
template<typename Type, typename... Types>
Void input(Type& arg, Types&... args){
    arg = read();
    input(args...);
}
Void dfs(int step, int limit){
    if(step > limit){
        if(now[limit] == n) flag = true;
        return;
    }
    for(ri i = step-1; i >= 0; i--) for(ri j = step-1; j >= i; j--){
        if(now[i] + now[j] > now[step-1]){
            now[step] = now[i] + now[j];
            dfs(step+1, limit);
            if(flag) return;
        }
    }
}
int main(){
//    File("dontthink")
    input(t);
    while(t--){
        flag = false;
        input(n);
        for(ri i = 0; i < 20; i++){
            dfs(1, i);
            if(flag){
//				write(i), puts("");
                for(ri j = 0; j <= i; j++) write(now[j]), putchar(' ');
                puts("");
                break;
            }
        }
    }
    return 0;
}