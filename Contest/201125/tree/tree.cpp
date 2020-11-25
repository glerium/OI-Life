#include <cstdio>
using namespace std;
const int maxn=5e6+10;
int n,m,head[maxn],cnt,fa[maxn],q[maxn],w[maxn],ct;
struct Edge{
	int to,nxt;
}a[maxn];
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
void dfs(int x){
	if(!w[x]) return;
	w[x]=0,ct--;
	for(int i=head[x];i;i=a[i].nxt) dfs(a[i].to);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	{
		scanf("%d%d",&n,&m);
		int a,b; scanf("%d%d",&a,&b);
		fa[2]=1;
		for(int i=3;i<=n;i++) fa[i]=((1ll*fa[i-1]*a+b)^19760817)%(i-1)+1;
		for(int i=2;i<=n;i++) add(fa[i],i);
	}
	int x,y; scanf("%d%d%d",&q[1],&x,&y);
	for(int i=1;i<=n;i++) w[i]=1;
	int ans=0;
	ct=n;
	for(int i=1;i<=m;i++){
		if(i!=1) q[i]=(((1ll*q[i-1]*x+y)^19760817)^(i<<1))%(n-1)+2;
		dfs(q[i]);
		ans^=ct;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
