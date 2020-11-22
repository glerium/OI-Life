#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,head[maxn],cnt,fa[maxn],sz[maxn];
struct Edge{
	int x,y,z;
	bool operator<(const Edge& rhs)const{return z<rhs.z;}
}a[maxn];
void add(int x,int y,int z){
	a[++cnt]=(Edge){x,y,z};
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y,z;i<=n-1;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	sort(a+1,a+n);
	ll ans=0;
	for(int i=1;i<n;i++){
		ans+=a[i].z;
		int x=find(a[i].x),y=find(a[i].y);
//		printf("%d\n",sz[x]);
		ans+=1ll*(a[i].z+1)*(sz[x]*sz[y]-1);
		fa[find(x)]=find(y);
		sz[y]+=sz[x];
	}
	printf("%lld\n",ans);
	return 0;
}
