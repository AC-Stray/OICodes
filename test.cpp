#include<iostream>
#define ll long long
#define step 100000
using namespace std;

ll a[step+5],b[step+5];

ll efind(ll k){
    int l=-1,r=step;
    while(l+1<r){
        int mid=(l+r)/2;
        if(a[mid]<=k)l=mid;
        else r=mid;
    }
    return l+1;
}

ll ans(ll k,ll m,ll n,ll l,ll r){
    if(r>m-1)r=m-1;
    for(int i=0;i<step;i++){//step只与时间时间复杂度有关，取到根号1e10最好
        a[i]=b[i]=k*i%m;    //存第一个循环节
    }
    ll derta=(ll)step*k%m;    //derta为全代码精华部分，代表每个step序列变值
    sort(a,a+step);            //前step个排序，便于二分查找
    ll res=0,now;            //rest计数，now控制遍历次数
    for(now=0;now+step<=n+1;now+=step){//需要遍历n/step次
        if(l<r)res+=efind(r)-efind(l-1);//二分查找在l-r之间的数的个数
        else res+=step-(efind(l-1)-efind(r));//小小的容斥原理
        l-=derta,r-=derta;
        if(l<0) l+=m;        //l,r始终要大于0
        if(r<0) r+=m;
        cout << l << " " << r << " " << res << endl;
    }
    for(ll i=now;i<=n;i++){                            // 最 后
        if( (l<=r && (b[i-now]>=l && b[i-now]<=r) ) ||   // 一 段
             (l>r && (b[i-now]>=l || b[i-now]<=r) ) )    // 直 接
        res++;                                // 暴 力
    }
    return res;
}

ll count(ll k,ll n,ll a,ll b,ll low,ll upp){
    cout << ans(k,n,b,low,upp) << endl;
    cout << ans(k, n, a-1, low, upp) << endl;
    return ans(k,n,b,low,upp)-ans(k,n,a-1,low,upp);      //前缀和
}

int main(){
    freopen("input.in", "r", stdin);
    ll k,n,l,r,u,v;
    cin>>k>>n>>l>>r>>u>>v;        // 输 入
    cout<<count(k,n,l,r,u,v);    // 输 出
    return 0;    // 完 结 撒 花
}