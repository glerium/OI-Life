#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m,cnt,head[maxn],sz[maxn],fa[maxn],dep[maxn],son[maxn],son2[maxn],top[maxn],dfn[maxn],ima;
int ov[maxn],ovtr[maxn],seg_ct;
struct Edge{
	int to,nxt,oval;
}a[maxn<<1];
struct Node{
	int l,r,ls,rs;
	int cnt3;
	bool one,two,three;
}t[maxn<<2];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
void add(int x,int y,int z){
	a[++cnt]=(Edge){y,head[x],z};
	head[x]=cnt;
}
void dfs1(int x,int fr){
	fa[x]=fr; sz[x]=1; dep[x]=dep[fr]+1;
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fr) continue; dfs1(a[i].to,x);
		sz[x]+=sz[a[i].to];
		if(sz[son[x]]<sz[a[i].to]) son[x]=a[i].to,son2[x]=a[i].oval;
	}
}
void dfs2(int x,int t){
	top[x]=t; dfn[x]=++ima;
	if(!son[x]) return;
	ov[son[x]]=son2[x]; dfs2(son[x],t);
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa[x]||a[i].to==son[x]) continue;
		ov[a[i].to]=a[i].oval;
		dfs2(a[i].to,a[i].to);
	}
}
void pushup(int x){
	t[x].one=t[t[x].ls].one|t[t[x].rs].one;
	t[x].two=t[t[x].ls].two|t[t[x].rs].two;
	t[x].three=t[t[x].ls].three|t[t[x].rs].three;
	t[x].cnt3=t[t[x].ls].cnt3+t[t[x].ls].cnt3;
}
int build(int l,int r){
	int x=++seg_ct; t[x].l=l,t[x].r=r;
	if(l==r){
		t[x].one=(ovtr[l]==1),t[x].two=(ovtr[l]==2),t[x].three=t[x].cnt3=(ovtr[l]==3);
		return x;
	}
	int mid=l+r>>1; t[x].ls=build(l,mid); t[x].rs=build(mid+1,r);
	pushup(x); return x;
}
void seg_change(int x,int l,int r){
	if(!t[x].two&&!t[x].three) return;
	if(l==r){
		if(!t[x].one){
			if(t[x].two) t[x].two=false,t[x].one=true;
			if(t[x].three) t[x].three=false,t[x].two=true;
		}
	}
	int mid=t[x].l+t[x].r>>1;
	seg_change(t[x].ls,l,mid);
	seg_change(t[x].rs,mid+1,r);
	pushup(x);
}
bool r1,r2,r3;
void seg_query(int x,int l,int r){
	r1=t[x].one,r2=t[x].two,r3=t[x].three;
}
void update(int x,int y){
	while(top[x]!=top[y]){
		if(dfn[top[x]]<dfn[top[y]]) swap(x,y);
		seg_change(1,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(dfn[x]>dfn[y]) swap(x,y);
	seg_change(1,dfn[x],dfn[y]);
}
bool query1(int x,int y){
	while(top[x]!=top[y]){
		if(dfn[top[x]]<dfn[top[y]]) swap(x,y);
		seg_query(1,dfn[top[x]],dfn[x]);
		if(!r3){
			x=fa[top[x]];
			continue;
		}
	}
}
int query2(int x){
	
}
int main(){
	freopen("brain.in","r",stdin);
	freopen("brain.out","w",stdout);
	read(n),read(m);
	for(int i=1,x,y,z;i<=n-1;i++){
		read(x),read(y),read(z);
		add(x,y,z),add(y,x,z);
	}
	dfs1(1,-1);
	dfs2(1,1);
	for(int i=1;i<=n;i++) ovtr[dfn[i]]=ov[i];
	build(1,n);
	for(int i=1,x,y,s,t;i<=m;i++){
		read(x),read(y),read(t),read(s);
		update(x,y);
		printf("%d %d\n",query1(s,t),query2(t));
	}
	return 0;
}
