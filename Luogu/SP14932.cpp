#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=2e3+10;
int t,n,m,head[maxn],cnt,f[maxn][20],sz[maxn],dfn[maxn],dep[maxn],fa[maxn],top[maxn],son[maxn],ima;
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
		if(sz[son[x]]<sz[a[i].to]) son[x]=a[i].to;
	}
}
void dfs2(int x,int t){
	top[x]=t;
	dfn[x]=++ima;
	if(!son[x]) return;
	dfs2(son[x],t);
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa[x]||a[i].to==son[x]) continue;
		dfs2(a[i].to,a[i].to);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]]) swap(x,y);
		y=fa[top[y]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	return x;
}
int main(){
	scanf("%d",&t);
	for(int kase=1;kase<=t;kase++){
		cnt=ima=0;
		memset(head,0,sizeof(head));
		memset(son,0,sizeof(son));
		scanf("%d",&n);
		printf("Case %d:\n",kase);
		for(int j=1,x;j<=n;j++){
			scanf("%d",&x);
			for(int k=1,r;k<=x;k++){
				scanf("%d",&r);
				add(j,r),add(r,j);
			}
		}
		dfs1(1,0); dfs2(1,1);
		scanf("%d",&m);
		for(int i=1,x,y;i<=m;i++){
			scanf("%d%d",&x,&y);
			printf("%d\n",lca(x,y));
		}
	}
	return 0;
}
