#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int n,q,cnt,head[maxn],dep[maxn];
ll val[maxn],ans[maxn];
struct Edge{
	int to,nxt;
}a[maxn];
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
ll dfs(int x,int fa){
	ll ans=0;
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		ans^=dfs(a[i].to,x);
	}
	ans^=val[x];
	return val[x]=ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1,x,y;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	for(int i=0;i<=n-1;i++) scanf("%lld",&val[i]);
	ans[0]=val[0];
	for(int i=1;i<=500;i++) ans[i]=dfs(0,0);
	for(int i=1,r;i<=q;i++){
		scanf("%d",&r);
		printf("%lld\n",ans[r]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
