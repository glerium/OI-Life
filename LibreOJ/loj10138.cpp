#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=6e4+10;
int n,m,cnt,head[maxn],w[maxn],trd[maxn],dfn[maxn],son[maxn],top[maxn],fa[maxn],sz[maxn],dep[maxn],ima,idx;
struct Edge{
	int to,nxt;
}a[maxn];
struct Node{
	int l,r;
	int ls,rs;
	int sum,max;
}t[maxn<<2];
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
	dfn[x]=++ima;
	top[x]=t;
	if(!son[x]) return;
	dfs2(son[x],t);
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa[x]||a[i].to==son[x]) continue;
		dfs2(a[i].to,a[i].to);
	}
}
void update(int x){
	t[x].max=max(t[t[x].ls].max,t[t[x].rs].max);
	t[x].sum=t[t[x].ls].sum+t[t[x].rs].sum;
}
int build(int l,int r){
	int id=++idx;
	t[id].l=l,t[id].r=r;
	if(l==r){
		t[id].max=t[id].sum=trd[l];
		return id;
	}
	int mid=l+r>>1;
	t[id].ls=build(l,mid);
	t[id].rs=build(mid+1,r);
	update(id);
	return id;
}
void tmodify(int x,int des,int v){
	if(t[x].l==t[x].r){
//		printf("%dff\n",des==t[x].l);
		t[x].max=t[x].sum=v;
		return;
	}
	int mid=t[x].l+t[x].r>>1;
	if(des<=mid) tmodify(t[x].ls,des,v);
	else tmodify(t[x].rs,des,v);
	update(x);
}
int tquerySum(int x,int l,int r){
	if(l<=t[x].l&&t[x].r<=r) return t[x].sum;
	int mid=t[x].l+t[x].r>>1,ans=0;
	if(l<=mid) ans+=tquerySum(t[x].ls,l,r);
	if(r>mid) ans+=tquerySum(t[x].rs,l,r);
	return ans;
}
int tqueryMax(int x,int l,int r){
//	printf("%d %d %d %d\n",t[x].l,t[x].r,t[x].ls,t[x].rs);
	if(l<=t[x].l&&t[x].r<=r) return t[x].max;
	int mid=t[x].l+t[x].r>>1,ans=-1e9;
	if(l<=mid) ans=max(ans,tqueryMax(t[x].ls,l,r));
	if(r>mid) ans=max(ans,tqueryMax(t[x].rs,l,r));
//	printf("%d %d %d: %d\n",x,l,r,ans);
	return ans;
}
int makeSum(int x,int y){
	if(top[x]<top[y]) swap(x,y);
	int ans=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ans+=tquerySum(1,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	ans+=tquerySum(1,dfn[x],dfn[y]);
	return ans;	
}
int makeMax(int x,int y){
	if(top[x]<top[y]) swap(x,y);
	int ans=-1e9;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ans=max(ans,tqueryMax(1,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	ans=max(ans,tqueryMax(1,dfn[x],dfn[y]));
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	dfs1(1,0); dfs2(1,1);
	for(int i=1;i<=n;i++) trd[dfn[i]]=w[i];
	build(1,n);
	char op[10];
	scanf("%d",&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%s%d%d",op,&x,&y);
		if(strcmp(op,"CHANGE")==0) tmodify(1,dfn[x],y);
		else if(strcmp(op,"QMAX")==0) printf("%d\n",makeMax(x,y));
		else printf("%d\n",makeSum(x,y));
	}
	return 0;
}
