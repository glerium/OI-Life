#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
const int maxm=1.4e6+10;
const int p=998244353;
int n,m,cnt,head[maxn],f[maxn],c[maxn];
struct Edge{
	int to,nxt;
}a[maxm];
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
long long qpow(long long x,long long y){
	long long ans=1;
	while(y){
		if(y&1) ans=ans*x%p;
		x=x*x%p, y>>=1;
	}
	return ans;
}
void dfs(int x){
	c[x]=1,f[x]=0;
	for(int i=head[x];i;i=a[i].nxt){
		if(f[a[i].to]==-1) dfs(a[i].to);
		c[x]=(c[x]+c[a[i].to])%p;
		f[x]=(f[x]+f[a[i].to]+c[a[i].to])%p;
	}
}
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++) if(f[i]==-1) dfs(i);
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		x=(x+f[i])%p;
		y=(y+c[i])%p;
	}
	printf("%d\n",1ll*x*qpow(y,p-2)%p);
	return 0;
}
