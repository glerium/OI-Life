//P4180 - BJWC2010
//krustal+lca
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int maxm=3e5+10;
int n,m,f[maxn],cnt,head[maxn],fa[maxn][20],dep[maxn];
ll mx[maxn][20],mi[maxn][20],ansori;
bool in[maxm];
struct Edge{
	int x,y;
	ll z;
	bool operator<(const Edge& rhs)const{return z<rhs.z;}
}a[maxm];
struct Edge2{
	int to;
	ll dis;
	int nxt;
}g[maxm];
void add(int x,int y,ll z){
	g[++cnt]=(Edge2){y,z,head[x]};
	head[x]=cnt;
}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x,int y){f[find(x)]=find(y);}
void krustal(){
	for(int i=1;i<=m;i++){
		if(find(a[i].x)==find(a[i].y)) continue;
		add(a[i].x,a[i].y,a[i].z);
		fa[a[i].y][0]=a[i].x;
		in[i]=true;
		ansori+=a[i].z;
		merge(a[i].x,a[i].y);
	}
}
void dfs(int x,int from,ll l){
//	fa[x][0]=from;
	dep[x]=dep[from]+1;
	mx[x][0]=l;
	mi[x][0]=-1e16;
	for(int i=head[x];i;i=g[i].nxt){
		if(g[i].to==fa[x][0]) continue;
		dfs(g[i].to,x,g[i].dis);
	}
}
int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=18;i>=0&&dep[x]<dep[y];i--){
		if(fa[x][i]&&dep[fa[x][i]]<=dep[y])
			x=fa[x][i];
	}
	if(x==y) return x;
	for(int i=18;i>=0;i--){
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
ll qmax(int x,int y,ll dis){
	ll ans=-1e16;
	for(int i=18;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]){
			if(dis!=mx[x][i]) ans=max(ans,mx[x][i]);
			else ans=max(ans,mi[x][i]);
			x=fa[x][i];
		}
	}
	return ans;
}
int main(){
//	freopen("test2.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		a[i]=(Edge){x,y,z};
	}
	sort(a+1,a+1+m);
	for(int i=1;i<=n;i++) f[i]=i,mi[i][0]=-1e16;
	krustal();
	dep[1]=0,mi[1][0]=-1e16;
	dfs(1,0,-1e16);
	for(int i=1;i<=18;i++){
		for(int x=1;x<=n;x++){
			fa[x][i]=fa[fa[x][i-1]][i-1];
			mx[x][i]=max(mx[x][i-1],mx[fa[x][i-1]][i-1]);
			mi[x][i]=max(mi[x][i-1],mi[fa[x][i-1]][i-1]);
			if(mx[x][i-1]>mx[fa[x][i-1]][i-1]) mi[x][i]=max(mi[x][i],mi[fa[x][i-1]][i-1]);
			else if(mx[x][i-1]<mx[fa[x][i-1]][i-1]) mi[x][i]=max(mi[x][i],mx[x][i-1]);
		}
	}
	ll ans=1e16;
	for(int i=1;i<=m;i++){
		if(in[i]) continue;
		int lc=lca(a[i].x,a[i].y);
		ll ans1=qmax(a[i].x,lc,a[i].z),
		   ans2=qmax(a[i].y,lc,a[i].z);
		ans=min(ans,ansori-max(ans1,ans2)+a[i].z);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=18;j++)
//			printf("%lld ",mx[i][j]);
//		puts("");
//	}
	printf("%lld\n",ans);
	return 0;
}
