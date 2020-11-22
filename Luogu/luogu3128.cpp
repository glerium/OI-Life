#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=5e4+10;
const int maxm=2e5+10;
int n,m,head[maxn],cnt,up[maxn][20],dep[maxn],f[maxn],ans[maxn];
struct Edge{
	int to,nxt;
}a[maxm];
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
void dfs(int x,int fa){
	up[x][0]=fa;
	for(int i=1;i<=18;i++) up[x][i]=up[up[x][i-1]][i-1];
	dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		dfs(a[i].to,x);
	}
}
int lca(int x,int y){
//	printf("%d %d: ",x,y);
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=18;i>=0&&dep[x]>dep[y];i--){
		if(!up[x][i]) continue;
		if(dep[up[x][i]]>=dep[y]) x=up[x][i];
	}
//	printf("%d %d\n",dep[x],dep[y]);
//	printf("%d %d,,",x,y);
	for(int i=18;i>=0&&x!=y;i--){
		if(!up[x][i]||!up[y][i]) continue;
		if(up[x][i]!=up[y][i]) x=up[x][i],y=up[y][i];
	}
//	printf("%d\n",x!=y?up[x][0]:x);
	if(x!=y) return up[x][0];
	else return x;
}
void dfs2(int x,int fa){
	ans[x]=f[x];
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		dfs2(a[i].to,x);
		ans[x]+=ans[a[i].to];
	}
}
int main(){
//	freopen("P3128_2.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	dfs(1,0);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		f[x]++,f[y]++;
		int k=lca(x,y);
		f[k]--,f[up[k][0]]--;
	}
	dfs2(1,0);
	int sjjAKIOI=0;
	for(int i=1;i<=n;i++)
		sjjAKIOI=max(sjjAKIOI,ans[i]);
	printf("%d\n",sjjAKIOI);
	return 0;
} 
