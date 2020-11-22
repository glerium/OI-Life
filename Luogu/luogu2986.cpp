#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,cnt,head[maxn],w[maxn];
ll dep[maxn],sz[maxn],f[maxn],sum;
struct Edge{
	int to,val,nxt;
}a[maxn];
void add(int x,int y,int z){
	a[++cnt]=(Edge){y,z,head[x]};
	head[x]=cnt;
}
void dfs1(int x,int fa){
	sz[x]=w[x];
	sum+=w[x];
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		dep[a[i].to]=dep[x]+a[i].val;
		dfs1(a[i].to,x);
		sz[x]+=sz[a[i].to];
	}
}
void dfs2(int x,int fa){
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		f[a[i].to]=f[x]+(sum-sz[a[i].to]*2)*a[i].val;
		dfs2(a[i].to,x);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1,x,y,z;i<=n-1;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z),add(y,x,z);
	}
	dfs1(1,0);
	for(int i=1;i<=n;i++) f[1]+=w[i]*dep[i];
	dfs2(1,0);
	ll ans=1e18;
	for(int i=1;i<=n;i++) ans=min(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}
