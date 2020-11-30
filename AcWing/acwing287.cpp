//»»¸ùdp 
#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int t,n,head[maxn],cnt,f[maxn],sz[maxn],siz[maxn];
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
		if(siz[a[i].to]==1) sz[x]+=a[i].dis;
		else sz[x]+=min(a[i].dis,sz[a[i].to]);
	}
}
void dfs2(int x,int fa){
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		if(siz[x]==1) f[a[i].to]=sz[a[i].to]+a[i].dis;
		else f[a[i].to]=sz[a[i].to]+min(f[x]-min(a[i].dis,sz[a[i].to]),a[i].dis);
		dfs2(a[i].to,x);
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		cnt=0;
		memset(head,0,sizeof(head));
		memset(f,0,sizeof(f));
		memset(sz,0,sizeof(sz));
		memset(siz,0,sizeof(siz));
		scanf("%d",&n);
		for(int i=1,x,y,z;i<=n-1;i++){
			scanf("%d%d%d",&x,&y,&z);
			siz[x]++,siz[y]++;
			add(x,y,z),add(y,x,z);
		}
		dfs1(1,0);
		f[1]=sz[1];
		dfs2(1,0);
		int ans=0;
		for(int i=1;i<=n;i++) ans=max(ans,f[i]),printf(":%d\n",f[i]);
		printf("%d\n",ans);
	}
	return 0;
}
