#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,s,head[maxn],cnt,mx[maxn];
long long ans;
struct Edge{
	int to,dis,nxt;
}a[maxn<<1];
void add(int x,int y,int z){
	a[++cnt]=(Edge){y,z,head[x]};
	head[x]=cnt;
}
void dfs1(int x,int fa){
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		dfs1(a[i].to,x);
		mx[x]=max(mx[x],mx[a[i].to]+a[i].dis);
	}
}
void dfs2(int x,int fa){
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		ans+=mx[x]-a[i].dis-mx[a[i].to];
		dfs2(a[i].to,x);
	}
}
int main(){
	scanf("%d%d",&n,&s);
	for(int i=1,x,y,z;i<=n-1;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z),add(y,x,z);
	}
	dfs1(s,0);
	dfs2(s,0);
	printf("%lld\n",ans);
	return 0;
}
