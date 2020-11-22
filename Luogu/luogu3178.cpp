#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m,w[maxn],ori[maxn],head[maxn],cnt,fa[maxn],dep[maxn],sz[maxn],top[maxn],son[maxn],id[maxn],dfn[maxn],low[maxn],ima,ct,idx;
struct Edge{
	int to,nxt;
}a[maxn];
struct Node{
	int l,r;
	int ls,rs;
	ll val,tag;
}t[maxn<<2];

template<typename T>void read(T& x){
	T v=0,w=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar();
	x=v*w;return;
}
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}

void dfs1(int x,int from){
	fa[x]=from;
	sz[x]=1;
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
	dfn[x]=low[x]=++ima;
	id[x]=++ct;
	if(son[x]) dfs2(son[x],t),low[x]=max(low[x],low[son[x]]);
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa[x]||a[i].to==son[x]) continue;
		dfs2(a[i].to,a[i].to);
		low[x]=max(low[x],low[a[i].to]);
	}
}

void update(int x){
	t[x].val=t[t[x].ls].val+t[t[x].rs].val;
}
void pushdown(int x){
	t[t[x].ls].tag+=t[x].tag;
	t[t[x].rs].tag+=t[x].tag;
	t[t[x].ls].val+=t[x].tag*(t[t[x].ls].r-t[t[x].ls].l+1);
	t[t[x].rs].val+=t[x].tag*(t[t[x].rs].r-t[t[x].rs].l+1);
	t[x].tag=0;
}
int build(int l,int r){
	int ii=++idx;
	t[ii].l=l,t[ii].r=r;
	if(l==r){
		t[ii].val=ori[l];
		return ii;
	}
	int mid=l+r>>1;
	t[ii].ls=build(l,mid);
	t[ii].rs=build(mid+1,r);
	update(ii);
	return ii;
}
void tadd(int x,int l,int r,ll v){
	if(t[x].tag) pushdown(x);
	if(l<=t[x].l&&t[x].r<=r){
		t[x].val+=v*(t[x].r-t[x].l+1);
		t[x].tag+=v;
		return;
	}
	int mid=t[x].l+t[x].r>>1;
	if(l<=mid) tadd(t[x].ls,l,r,v);
	if(r>mid) tadd(t[x].rs,l,r,v);
	update(x);
}
ll tquery(int x,int l,int r){
	if(t[x].tag) pushdown(x);
	if(l<=t[x].l&&t[x].r<=r) return t[x].val;
	int mid=t[x].l+t[x].r>>1;
	ll ans=0;
	if(l<=mid) ans+=tquery(t[x].ls,l,r);
	if(r>mid) ans+=tquery(t[x].rs,l,r);
	return ans;
}

ll query(int x){
	ll ans=0;
	while(x){
		ans+=tquery(1,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	return ans;
}

int main(){
	read(n),read(m);
	for(int i=1;i<=n;i++) read(w[i]);
	for(int i=1,x,y;i<=n-1;i++){
		read(x),read(y);
		add(x,y),add(y,x);
	}
	dfs1(1,0); dfs2(1,1);
	for(int i=1;i<=n;i++) ori[dfn[i]]=w[i];
	build(1,n);
	for(int i=1,op,x,y;i<=m;i++){
		read(op),read(x);
		if(op==1){
			read(y);
			tadd(1,dfn[x],dfn[x],y);
		}else if(op==2){
			read(y);
			tadd(1,dfn[x],low[x],y);
		}else{
			printf("%lld\n",query(x));
		}
	}
	return 0;
}
