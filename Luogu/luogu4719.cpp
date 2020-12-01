#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m,w[maxn],cnt,head[maxn],dep[maxn],sz[maxn],fa[maxn],son[maxn],dfn[maxn],top[maxn],fuka[maxn],ima,toid[maxn];
int seg_ct;
ll f[maxn][2];
struct Edge{
	int to,nxt;
}a[maxn<<1];
struct Matrix{
	int a[2][2];
	Matrix(){memset(a,0xc0,sizeof(a));}
	Matrix operator*(const Matrix& rhs)const{
		Matrix ans;
		for(int k=0;k<2;k++){
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					ans.a[i][j]=max(ans.a[i][j],a[i][k]+rhs.a[k][j]);
				}
			}
		}
		return ans;
	}
}val[maxn];
struct Node{
	int l,r,ls,rs;
	Matrix val;
}t[maxn<<2];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar();
	x=v*w;return;
}
template<typename T>void write(T x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
void dfs1(int x,int from){
	fa[x]=from; dep[x]=dep[from]+1; sz[x]=1;
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==from) continue;
		dfs1(a[i].to,x);
		sz[x]+=sz[a[i].to];
		if(sz[a[i].to]>sz[son[x]]) son[x]=a[i].to;
	}
}
void dfs2(int x,int t){
	dfn[x]=++ima;
	toid[ima]=x;
	top[x]=t;
	fuka[t]=max(fuka[t],dfn[x]);
	f[x][0]=0; f[x][1]=w[x];
	val[x].a[0][0]=val[x].a[0][1]=0;
	val[x].a[1][0]=w[x];
	if(!son[x]) return;
	dfs2(son[x],t);
	f[x][0]+=max(f[son[x]][0],f[son[x]][1]);
	f[x][1]+=f[son[x]][0];
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==son[x]||a[i].to==fa[x]) continue;
		dfs2(a[i].to,a[i].to);
		val[x].a[0][0]+=max(f[a[i].to][0],f[a[i].to][1]);
		val[x].a[0][1]=val[x].a[0][0];
		val[x].a[1][0]+=f[a[i].to][0];
		f[x][0]+=max(f[a[i].to][0],f[a[i].to][1]);
		f[x][1]+=f[a[i].to][0];
	}
}
void update(int x){
	t[x].val=t[t[x].ls].val*t[t[x].rs].val;
}
int build(int l,int r){
	int x=++seg_ct;
	t[x].l=l,t[x].r=r;
	if(l==r){
		t[x].val=val[toid[l]];
		return x;
	}
	int mid=l+r>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
	update(x);
	return x;
}
void seg_edit(int x,int v){
	if(t[x].l==t[x].r){
		t[x].val=val[toid[v]];
		return;
	}
	int mid=t[x].l+t[x].r>>1;
	if(v<=mid) seg_edit(t[x].ls,v);
	else seg_edit(t[x].rs,v);
	update(x);
}
Matrix seg_query(int x,int l,int r){
	if(t[x].l==l&&t[x].r==r) return t[x].val;
	int mid=t[x].l+t[x].r>>1;
	if(r<=mid) return seg_query(t[x].ls,l,r);
	if(l>mid) return seg_query(t[x].rs,l,r);
	return seg_query(t[x].ls,l,mid)*seg_query(t[x].rs,mid+1,r);
}
void make_update(int x,int v){
	val[x].a[1][0]+=v-w[x];
	w[x]=v;
	Matrix bef,aft;
	while(x){
		bef=seg_query(1,dfn[top[x]],fuka[top[x]]);
		seg_edit(1,dfn[x]);
		aft=seg_query(1,dfn[top[x]],fuka[top[x]]);
		x=fa[top[x]];
		val[x].a[0][0]+=max(aft.a[0][0],aft.a[1][0])-max(bef.a[0][0],bef.a[1][0]);
		val[x].a[0][1]=val[x].a[0][0];
		val[x].a[1][0]+=aft.a[0][0]-bef.a[0][0];
	}
}
int main(){
	read(n),read(m);
	for(int i=1;i<=n;i++) read(w[i]);
	for(int i=1,x,y;i<=n-1;i++){
		read(x),read(y);
		add(x,y),add(y,x);
	}
	dfs1(1,0); dfs2(1,1);
	build(1,n);
//	for(int i=1;i<=2*n;i++) printf("%d %d: %d %d %d\n",t[i].l,t[i].r,t[i].val.a[0][0],t[i].val.a[0][1],t[i].val.a[1][0]);
	int las=0;
	for(int i=1,x,y;i<=m;i++){
		read(x),read(y);
		make_update(x^las,y);
		Matrix ans=seg_query(1,dfn[1],fuka[1]);
		write(las=max(ans.a[0][0],ans.a[1][0])); putchar('\n');
//		for(int i=1;i<=2*n;i++) printf("%d %d: %d %d %d\n",t[i].l,t[i].r,t[i].val.a[0][0],t[i].val.a[0][1],t[i].val.a[1][0]);	
	}
	return 0;
}
