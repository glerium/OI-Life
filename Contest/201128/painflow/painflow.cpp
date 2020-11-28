#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int p=998244353;
int n,k,head[maxn],cnt,sz[maxn],top[maxn],son[maxn],fa[maxn],dep[maxn];
struct Edge{
	int to,nxt;
}a[maxn<<1];
struct Edge2{
	int x,y;
}b[maxn<<1];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch)){v=v*10+ch-'0';ch=getchar ();}
	x=v*w; return;
}
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
void dfs1(int x,int fr){
	sz[x]=1;
	dep[x]=dep[fr]+1;
	fa[x]=fr;
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fr) continue;
		dfs1(a[i].to,x);
		sz[x]+=sz[a[i].to];
		if(sz[son[x]]<sz[a[i].to]) son[x]=a[i].to;
	}
}
void dfs2(int x,int t){
	top[x]=t;
	if(!son[x]) return;
	dfs2(son[x],t);
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa[x]||a[i].to==son[x]) continue;
		dfs2(a[i].to,a[i].to);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
ll qpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%p;
		x=x*x%p; y>>=1;
	}
	return ans;
}
int main(){
	freopen("painflow.in","r",stdin);
	freopen("painflow.out","w",stdout);
	read(n),read(k);
	for(int i=1,x,y;i<=n-1;i++){
		read(x),read(y);
		add(x,y),add(y,x);
		b[i]=(Edge2){x,y};
	}
	dfs1(1,0),dfs2(1,0);
	if(k==1){
		ll ans=0;
		for(int i=1;i<=n-1;i++){
			int x=b[i].x,y=b[i].y;
			if(dep[x]<dep[y]) ans=(ans+1ll*sz[y]*(n-sz[y]))%p;
			else ans=(ans+1ll*sz[x]*(n-sz[x]))%p;
		}
		printf("%lld\n",ans);
	}else{
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=(ans+qpow(dep[i]+dep[j]-2*dep[lca(i,j)],k))%p;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
