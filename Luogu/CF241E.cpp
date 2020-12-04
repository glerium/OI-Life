#include <bits/stdc++.h>
using namespace std;
const int maxn=4e3+10;
int n,m,head[maxn],head2[maxn],head3[maxn],cnt,cnt1,cnt2,dis[maxn],inc[maxn];
bool vis[maxn],vis3[maxn],inq[maxn],flag[maxn];
struct Edge{
	int from,to,dis,nxt;
}a[maxn],a1[maxn],b[maxn];
void add(int x,int y){
	a[++cnt]=(Edge){x,y,0,head[x]};
	head[x]=cnt;
}
void add2(int x,int y,int z){
	b[++cnt2]=(Edge){x,y,z,head2[x]};
	head2[x]=cnt2;
}
void add3(int x,int y){
	a1[++cnt1]=(Edge){x,y,0,head3[x]};
	head3[x]=cnt1;
}
void dfs(int x){
	for(int i=head[x];i;i=a[i].nxt){
		if(!vis[a[i].to]){
			vis[a[i].to]=true;
			dfs(a[i].to);
		}
	}
}
void dfs2(int x){
	for(int i=head3[x];i;i=a1[i].nxt){
		if(!vis3[a1[i].to]){
			vis3[a1[i].to]=true;
			dfs2(a1[i].to); 
		}
	}
}
void spfa(int x){
	memset(dis,0xc0,sizeof(dis));
	queue<int> q;
	dis[x]=0; q.push(x);
	inq[x]=true; inc[x]++;
	while(!q.empty()){
		int cr=q.front(); q.pop(); inq[cr]=false;
		for(int i=head2[cr];i;i=b[i].nxt){
			if(dis[b[i].to]<dis[cr]+b[i].dis){
				dis[b[i].to]=dis[cr]+b[i].dis;
				if(!inq[b[i].to]){
					q.push(b[i].to);
					inq[b[i].to]=true;
					inc[b[i].to]++;
					if(inc[b[i].to]>n){
						puts("-1");
						exit(0);
					}
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y), add(x,y),add3(y,x);
	dfs(1); dfs2(n);
	if(!vis[n]){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++) if(vis[i]&&vis3[i]) flag[i]=true;
	flag[1]=flag[n]=true;
	for(int i=1;i<=m;i++) if(flag[a[i].from]&&flag[a[i].to]) add2(a[i].from,a[i].to,1),add2(a[i].to,a[i].from,-9);
	spfa(1);
	printf("%d %d\n",n,m);
	for(int i=1;i<=cnt;i++) printf("%d %d %d\n",a[i].from,a[i].to,flag[a[i].from]&&flag[a[i].to]?dis[a[i].to]-dis[a[i].from]:1);
	return 0;
} 
