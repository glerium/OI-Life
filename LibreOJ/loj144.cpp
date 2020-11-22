#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e6+10;
int n,m,rt,cnt,head[maxn],dfn[maxn],ed[maxn],ima;
ll f[maxn],w[maxn];
struct Edge{
	int to,nxt;
}a[maxn<<1];
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
void dfs(int x,int fa){
	dfn[x]=ed[x]=++ima;
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		dfs(a[i].to,x);
		ed[x]=max(ed[x],ed[a[i].to]);
	}
}
int lowbit(int x){return x&-x;}
void tadd(int k,ll x){
	while(k<=n){
		f[k]+=x;
		k+=lowbit(k);
	}
}
ll tsum(int x){
	ll ans=0;
	while(x){
		ans+=f[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
//	freopen("144_2.in","r",stdin);
//	freopen("144_2.out","w",stdout);
	scanf("%d%d%d",&n,&m,&rt);
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	for(int i=1,x,y;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	dfs(rt,0);
	for(int i=1;i<=n;i++) tadd(dfn[i],w[i]);
	for(int i=1,op,x,y;i<=m;i++){
		scanf("%d%d",&op,&x);
		if(op==1) scanf("%d",&y),tadd(dfn[x],y);
		else printf("%lld\n",tsum(ed[x])-tsum(dfn[x]-1));
	}
	return 0;
} 
