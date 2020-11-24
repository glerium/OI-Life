#include <cstdio>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
const int p=1e9+7;
int n,head[maxn],cnt;
ll w[maxn],ans,f[maxn][2],f2[maxn][2];
long double ansd,g[maxn][2];
struct Ans{
	ll val,cnt;
	bool operator<(const Ans& rhs)const{return cnt!=rhs.cnt?cnt<rhs.cnt:val<rhs.val;}
	Ans operator*(const Ans& rhs)const{
		return (Ans){val*rhs.val,cnt+rhs.cnt};
	}
};
struct Edge{
	int to,nxt;
}a[maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
void dfs(int x,int fa){
	f[x][0]=1;
	g[x][0]=0;
	f[x][1]=w[x];
	g[x][1]=log2(w[x]);
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		dfs(a[i].to,x);
		if(g[a[i].to][1]>g[a[i].to][0]){
			f[x][0]=f[x][0]*f[a[i].to][1]%p;
			g[x][0]=g[x][0]+g[a[i].to][1];
		}else{
			f[x][0]=f[x][0]*f[a[i].to][0]%p;
			g[x][0]=g[x][0]+g[a[i].to][0];
		}
		f[x][1]=f[x][1]*f[a[i].to][0]%p;
		g[x][1]=g[x][1]+g[a[i].to][0];
	}
	if(g[x][1]>ansd){
		ansd=g[x][1];
		ans=f[x][1];
	}else{
		ansd=g[x][0];
		ans=f[x][0];
	}
}
void dfsS3(int x,int fa){
	f2[x][0]=0;
	f2[x][1]=(w[x]==2);
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		dfsS3(a[i].to,x);
		f2[x][0]+=max(f2[a[i].to][1],f2[a[i].to][0]);
		f2[x][1]+=f2[a[i].to][0];
	}
	ans=max(ans,max(f2[x][0],f2[x][1]));
}
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	read(n);
	bool issub3=true;
	for(int i=1;i<=n;i++) read(w[i]),issub3&=(w[i]<=2);
	for(int i=1,x,y;i<=n-1;i++){
		read(x),read(y);
		add(x,y),add(y,x);
	}
	if(issub3){
		dfsS3(1,0);
		ll kk=1;
		for(int i=1;i<=ans;i++) kk=kk*2%p;
		printf("%lld\n",kk);
	}else{
		dfs(1,0);
		if(g[1][1]>g[1][0]) printf("%lld\n",f[1][1]);
		else printf("%lld\n",f[1][0]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
