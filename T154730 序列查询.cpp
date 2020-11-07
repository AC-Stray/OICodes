#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll step = 100000;
ll k, mo, l, r, u, v;
ll add, ori[step+5], sorted[step+5];
ll solve(ll n){
    ll res = 0, fu = u, fv = v, now;
    for(now = 0; now + step <= n; now += step){
        if(fu < fv)
            res += upper_bound(sorted, sorted+step, fv) - upper_bound(sorted, sorted+step, fu-1);
        else
            res += step - (upper_bound(sorted, sorted+step, fu-1) - upper_bound(sorted, sorted+step, fv));
        fu = (fu - add + mo) % mo, fv = (fv - add + mo) % mo;
    }
    for(; now <= n; now++)
        if(fu <= fv && ori[now%step] >= fu && ori[now%step] <= fv ||
           fv < fu && (ori[now%step] >= fu || ori[now%step] <= fv))
            res++;
    return res;
}
int main(){
    freopen("input.in", "r", stdin);
    cin >> k >> mo >> l >> r >> u >> v;
    for(int i = 0; i < step; i++)
        ori[i] = sorted[i] = i * k % mo;
    sort(sorted, sorted+step);
    add = step * k % mo;
    if(u >= mo){
        cout << 0;
        return 0;
    }
    if(v >= mo) v = mo - 1;
    cout << solve(r) - solve(l-1);
    return 0;
}