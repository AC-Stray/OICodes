#include <bits/stdc++.h>
using namespace std;
const int N=5050;
int t;
int n,m,s;
struct point
{
	int v,w,next;
}p[N];
int h[N],tail=0;
int fa[N];
int find(int now)
{
	if(fa[now]!=now)
		fa[now]=find(fa[now]);
	return fa[now];
}
void insert(int u,int v,int w)
{
	p[++tail].v=v;
	p[tail].w=w;
	p[tail].next=h[u];
	h[u]=tail;
}
int dis[N];
int tag[N];
void dfs(int now,int len)
{
	int i;
	dis[now]=len;
	tag[now]=1;
	for(i=h[now];i;i=p[i].next)
	{
		if(!tag[p[i].v])
			dfs(p[i].v,len+p[i].w);
	}
}
void yc()
{
	cin>>n>>m>>s;
	int i,j;
	int p,q,r;
	tail=0;
	memset(h,0,sizeof(h));
	int x=0;
	memset(dis,0,sizeof(dis));
	memset(tag,0,sizeof(tag));
	for(i=1;i<=n;i++)
		fa[i]=i;
	for(i=1;i<=m;i++)
	{
		cin>>p>>q>>r;
		if(x)
			continue;
		if(find(p)==find(q))
		{
			x=1;
			cout<<"YES"<<endl;//自环 
		}
		insert(p,q,r);
		insert(q,p,r);
		fa[find(p)]=q;
	}
	if(x)
		return;
	//有环直接输出，无环就判树的直径 
	int ans=0,st;
	for(i=1;i<=n;i++)
	{
		if(!dis[i])
		{
			dfs(i,0);
			for(j=1;j<=n;j++)
			{
				if(dis[j]>ans)
				{
					ans=dis[j];
					st=j;
				}
			}
		}
	}
	memset(tag,0,sizeof(tag));
	dfs(st,0);
	for(i=1;i<=n;i++)
		ans=max(ans,dis[i]);
	if(ans<s){
		cout << ans << endl;
		cout<<"NO"<<endl;
	}
	else
		cout<<"YES"<<endl;
	return;
}
int main()
{
	cin>>t;
	while(t>0)
	{
		t--;
		yc();
	}
	return 0;
}
