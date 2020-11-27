#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
const int p=998244353;
int n,head[maxn],cnt,a[maxn],f[maxn][maxn],dep,d[maxn],fa[maxn][maxn];
struct Edge{int to,nxt;}t[maxn<<1];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch)){v=v*10+ch-'0';ch=getchar ();}
	x=v*w; return;
}
void add(int x,int y){t[++cnt]=(Edge){y,head[x]};head[x]=cnt;}
ll qpow(ll x,ll y) {ll ans=1; while(y){if(y&1)ans=ans*x%p; x=x*x%p; y>>=1;} return ans%p;}
int dfs1(int x,int from){
	fa[x][0]=from;
	for(int i=1;i<=dep;i++) fa[x][i]=fa[fa[x][i-1]][0];
	d[x]=d[from]+1;
	int mx=0;
	for(int i=head[x];i;i=t[i].nxt){
		if(t[i].to==from) continue;
		mx=max(mx,dfs1(t[i].to,x));
	}
	return d[x]+mx;
}
int dfs2(int x,int fa,int dep){
	if(f[x][dep]) return f[x][dep];
	if(dep==0) return f[x][dep]=1;
	f[x][dep]=1;
	for(int i=head[x];i;i=t[i].nxt){
		if(t[i].to==fa) continue;
		f[x][dep]=1ll*dfs2(t[i].to,x,dep-1)*f[x][dep]*a[t[i].to]%p;
	}
	return f[x][dep]*1ll%p;
}
ll dfs3(int x,int dep,int ori){
	ll ans=f[x][dep];
	if(x!=1) ans=(ans+dfs3(fa[x][0],dep+1,ori)*qpow(ori,p-2))%p;
	return ans;
}
int main(){
	freopen("animal.in","r",stdin); freopen("animal.out","w",stdout);
	read(n);
	for(int i=1,cn=qpow(100,p-2),x;i<=n;i++) read(x),a[i]=1ll*(100-x)*cn%p;
	for(int i=1,x,y;i<=n-1;i++) read(x),read(y),add(x,y),add(y,x);
	dep=dfs1(1,0);
	for(int i=0;i<=dep;i++) dfs2(1,0,i);
	for(int i=1;i<=n;i++){
		printf("%lld\n",dfs3(i,0,a[i]));
	}
	return 0;
}
