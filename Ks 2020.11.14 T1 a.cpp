#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
ll n;
vector<ll>ans;
int main(){
    scanf("%lld", &n);
    for(ll i = n - 200; i <= n; i++){
        ll t = i, sum = 0;
        while(t) sum += t % 10, t /= 10;
        if(sum + i == n) ans.push_back(i);
    }
    printf("%lu\n", ans.size());
    for(ll i = 0; i < ans.size(); i++) printf("%lld\n", ans[i]);
    return 0;
}