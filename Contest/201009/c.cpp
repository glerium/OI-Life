#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,m,s,t,x,y,head[maxn],cnt,fa[maxn],dep[maxn];
ll depx[maxn];
bool v1[maxn],v2[maxn];
struct Edge{
	int to,nxt;
	ll dis;
}a[maxn];

template<typename T> void read(T& x){
	T v=0,w=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') w=-1; ch=getchar();}
	while(ch<='9'&&ch>='0'){v=v*10+ch-'0'; ch=getchar();}
	x=v*w; return;
}

void add(int x,int y,ll z){
	a[++cnt]=(Edge){y,head[x],z};
	head[x]=cnt; return;
}
void dfs(int x,int from){
	fa[x]=from;
	dep[x]=dep[from]+1;
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==from) continue;
		depx[a[i].to]=depx[x]+a[i].dis;
		dfs(a[i].to,x);
	}
}
void dfs_dye(int x,int des,int op){
	if(x==des) return;
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa[x]){
			if(op==1) v1[i]=true;
			else v2[i]=true;
			dfs_dye(a[i].to,des,op);
			return;
		}
	}
}

int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	read(n),read(m),read(s),read(t),read(x),read(y);
	for(int i=1,_x,_y,_z;i<=m;i++){
		read(_x),read(_y),read(_z);
		add(_x,_y,_z); add(_y,_x,_z);
	}
	dfs(1,0);
	int ca=s,cb=t,lca1,lca2;
	while(ca!=cb){
		if(dep[ca]<dep[cb]) cb=fa[cb];
		else ca=fa[ca];
	}
	lca1=ca;
	ca=x,cb=y;
	while(ca!=cb){
		if(dep[ca]<dep[cb]) cb=fa[cb];
		else ca=fa[ca];
	}
	lca2=ca;
	dfs_dye(s,lca1,1); dfs_dye(t,lca1,1);
	dfs_dye(x,lca2,2); dfs_dye(y,lca2,2);
	ll ans=depx[x]+depx[y]-depx[lca2]*2;
	for(int i=1;i<=m*2;i++)
		if(v1[i]&&v2[i]) ans-=a[i].dis;
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
