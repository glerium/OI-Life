#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e6+10;
int n,cnt,head[maxn],sz[maxn],dep[maxn];
long long f[maxn];
struct Edge{
	int to,nxt;
}a[maxn<<1];
void add(int x,int y){a[++cnt]=(Edge){y,head[x]};head[x]=cnt;}
void dfs1(int x,int fa){
	sz[x]=1; dep[x]=x==1?0:dep[fa]+1;
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		dfs1(a[i].to,x);
		sz[x]+=sz[a[i].to];
	}
}
void dfs2(int x,int fa){
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		f[a[i].to]=f[x]+n-sz[a[i].to]*2;
		dfs2(a[i].to,x);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	dfs1(1,0);
	for(int i=1;i<=n;i++) f[1]+=dep[i];
	dfs2(1,0);
	long long ans=0,ai;
	for(int i=1;i<=n;i++) if(f[i]>ans) ans=f[i],ai=i;
	printf("%d\n",ai);
	return 0;
}
