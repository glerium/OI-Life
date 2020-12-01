#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=107;
int n,m,k,e,d,cnt,head[maxn],fans[maxn],dis[maxn];
ll f[maxn],av[maxn];
bool avai[maxn][maxn],vis[maxn];
struct Edge{
	int to,dis,nxt;
}a[maxn*maxn<<1];
struct Node{
	int id,dis;
	bool operator<(const Node& rhs)const{return dis>rhs.dis;}
};
priority_queue<Node> q;
void add(int x,int y,int z){
	a[++cnt]=(Edge){y,z,head[x]};
	head[x]=cnt;
}
ll dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0; q.push((Node){1,0});
	while(!q.empty()){
		Node cr=q.top(); q.pop();
		if(vis[cr.id]) continue;
		vis[cr.id]=true;
		for(int j=head[cr.id];j;j=a[j].nxt){
			if(av[a[j].to]) continue;
			if(dis[a[j].to]>dis[cr.id]+a[j].dis){
				dis[a[j].to]=dis[cr.id]+a[j].dis;
				q.push((Node){a[j].to,dis[a[j].to]});
			}
		}
	}
	return dis[m];
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&e);
	for(int i=1,x,y,z;i<=e;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z),add(y,x,z);
	}
	memset(avai,0,sizeof(avai));
	scanf("%d",&d);
	for(int i=1,p,a,b;i<=d;i++){
		scanf("%d%d%d",&p,&a,&b);
		for(int j=a;j<=b;j++) avai[p][j]=true;
	}
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++){
		memset(av,0,sizeof(av));
		for(int j=i;j>=1;j--){
			for(int t=1;t<=m;t++) av[t]|=avai[t][j];
			ll tp=dijkstra();
			f[i]=min(f[i],f[j-1]+tp*(i-j+1)+k);
		}
	}
	printf("%lld\n",f[n]-k);
	return 0;
}
