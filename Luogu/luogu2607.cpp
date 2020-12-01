#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,cnt,head[maxn],w[maxn],rt,fa[maxn];
long long ans,f[maxn][2];
bool vis[maxn];
struct Edge{
	int to,nxt;
}a[maxn<<1];
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
void dfs(int x){
	vis[x]=true;
	f[x][1]=w[x],f[x][0]=0;
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to!=rt){
			dfs(a[i].to);
			f[x][1]+=f[a[i].to][0];
			f[x][0]+=max(f[a[i].to][0],f[a[i].to][1]);
		}else f[a[i].to][1]=-1e17;
	}
}
void find_circle(int x){
	rt=x;
	while(!vis[fa[rt]]){
		vis[rt]=true;
		rt=fa[rt];
	}
	vis[rt]=true;
	long long imans=-1;
	dfs(rt); imans=max(f[rt][0],f[rt][1]);
	rt=fa[rt]; dfs(rt); imans=max(imans,max(f[rt][0],f[rt][1]));
	ans+=imans;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d%d",&w[i],&x);
		add(x,i); fa[i]=x;
	}
	for(int i=1;i<=n;i++) if(!vis[i]) find_circle(i);
	printf("%lld\n",ans);
	return 0;
}
