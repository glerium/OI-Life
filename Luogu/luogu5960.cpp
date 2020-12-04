#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m,head[maxn],cnt,dis[maxn],inct[maxn];
bool inque[maxn];
struct Edge{
	int to,dis,nxt;
}a[maxn];
void add(int x,int y,int z){
	a[++cnt]=(Edge){y,z,head[x]};
	head[x]=cnt;
}
queue<int> q;
bool spfa(){
	memset(dis,0xc0,sizeof(dis));
	dis[0]=0;
	inque[0]=true;
	q.push(0);
	while(!q.empty()){
		int x=q.front(); q.pop();
		inque[x]=false;
		for(int i=head[x];i;i=a[i].nxt){
			if(dis[a[i].to]<dis[x]+a[i].dis){
				dis[a[i].to]=dis[x]+a[i].dis;
				if(!inque[a[i].to]){
					q.push(a[i].to);
					inque[a[i].to]=true;
					inct[a[i].to]++;
					if(inct[a[i].to]>n+1) return false;
				}
			}
		}
	}
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) add(0,i,0);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,-z);
	}
	if(spfa()) for(int i=1;i<=n;i++) printf("%d ",dis[i]);
	else puts("NO");
	return 0;
}
