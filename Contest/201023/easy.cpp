#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,cnt,head[maxn],dep[maxn],mindep[maxn],p[maxn],ff[maxn][18],as[5007][5007],lc[5007][5007];
struct Edge{
	int to,nxt;
}a[maxn];
struct Num{
	int x,rank;
}num[maxn];
template<typename T>void read(T& x){
	T v=0,w=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){v=v*10+ch-'0';ch=getchar();}
	x=v*w; return;
}
void add(int x,int y){a[++cnt]=(Edge){y,head[x]};head[x]=cnt;}
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	ff[x][0]=fa;
	for(int i=1;i<=16;i++) ff[x][i]=ff[ff[x][i-1]][i-1];
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		dfs(a[i].to,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	int lx=x,ly=y;
	if(lc[x][y]) return lc[x][y];
//	printf("%d %d: ",x,y);
	while(dep[x]>dep[y]){
		for(int i=16;i>=0;i--)
			if(dep[ff[x][i]]>=dep[y]) x=ff[x][i];
	}
	while(ff[x][0]!=ff[y][0]){
		for(int i=16;i>=0;i--)
			if(ff[x][i]!=ff[y][i]) x=ff[x][i],y=ff[y][i];
	}
	if(x!=y) x=ff[x][0],y=ff[y][0];
//	printf("%d\n",x);
	return lc[lx][ly]=x;
}
void dp(){
	for(int i=1;i<=n;i++) as[i][i]=p[i];
	for(int k=2;k<=n;k++){
		for(int l=1,r=l+k-1;l<=n&&r<=n;l++,r++)
			as[l][r]=lca(as[l][r-1],p[r]);
	}
}
int main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	read(n);
	bool islink=true;
	for(int i=1,x,y;i<=n-1;i++){
		read(x),read(y);
		add(x,y),add(y,x);
		if(y-x!=1&&x-y!=1) islink=false;
	}
	for(int i=1;i<=n;i++) read(p[i]);
	if(islink){
		ll ans=0;
		for(int i=1;i<=n;i++) ans+=(n-p[i]+1)*p[i];
		printf("%lld\n",ans);
		return 0;
	}
	ll ans=0;
	dfs(1,0);
	dp();
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
			ans+=dep[as[i][j]];
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(j<i) printf("  ");
//			else printf("%d ",dep[as[i][j]]);
//		}
//		puts("");
//	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
