#include<cstdio>
#include<algorithm>
using namespace std;
int t, n, m, res, a[100005];
bool flag;
int main(){
    freopen("input.in", "r", stdin);
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            res = 0;
            while(a[i] % 2 == 0) a[i] /= 2, res++;
            a[i] = res;
        }
        sort(a, a+n);
        flag = true;
        for(int i = 0; i < n / 2; i++)
            if(a[i] + a[n-i-1] < m){
                flag = false;
                break;
            }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}