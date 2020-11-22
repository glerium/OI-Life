#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=6e5+10;
int n,m,head[maxn],cnt,fa[maxn],sz[maxn],dep[maxn],top[maxn],dfn[maxn],son[maxn],ima;
int w[maxn],st[maxn],ed[maxn];
struct Edge{
	int to,nxt;
}a[maxn];
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
void dfs1(int x,int from){
	sz[x]=1;
	fa[x]=from;
	dep[x]=dep[fa[x]]+1;
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa[x]) continue;
		dfs1(a[i].to,x);
		sz[x]+=sz[a[i].to];
		if(sz[a[i].to]>sz[son[x]]) son[x]=a[i].to;
	}
}
void dfs2(int x,int t){
	top[x]=t;
	dfn[x]=++ima;
	if(!son[x]) return;
	dfs2(son[x],t);
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==son[x]||a[i].to==fa[x]) continue;
		dfs2(a[i].to,a[i].to);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]]) swap(x,y);
		y=fa[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
void dfs3(int x){
	
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	dfs1(1,0),dfs2(1,1);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		int lc=lca(x,y);
		st[x]++;
	}
	
	return 0;
}
