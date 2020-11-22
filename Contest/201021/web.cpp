#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
const int maxn=2e5+10;
const int maxm=5e6+10;
int n,s,m,dis[maxn],cnt,head[maxn],inc[maxn];
bool inq[maxn];
set<int> st;
queue<int> q;
struct Edge{
	int to,nxt,dis;
}a[maxm*10];
void add(int x,int y,int z){
	a[++cnt]=(Edge){y,head[x],z};
	head[x]=cnt;
}
bool spfa(int x){
//	printf("%d\n",x);
	q.push(x);
	inc[x]++; inq[x]=true;
	while(!q.empty()){
//		printf("::%d\n",q.front());
		int cur=q.front(); q.pop(); inq[cur]=false;
		for(int i=head[cur];i;i=a[i].nxt){
			if(st.count(a[i].to)) continue;
//			printf("%d\n",a[i].to);
			if(dis[a[i].to]>dis[x]+a[i].dis){
				dis[a[i].to]=dis[x]+a[i].dis;
				if(!inq[a[i].to]){
					q.push(a[i].to);
					inq[a[i].to]=true;
					inc[a[i].to]++;
				}
			}
			if(inc[a[i].to]>n) return 0;
		}
	}
	return 1;
}
int main(){
//	freopen("web.in","r",stdin);
//	freopen("web.out","w",stdout);
	scanf("%d%d%d",&n,&s,&m);
	for(int i=1,x,y;i<=s;i++) scanf("%d%d",&x,&y),dis[x]=y,st.insert(x);
	for(int i=1,l,r,k;i<=m;i++){
		scanf("%d%d%d",&l,&r,&k);
		bool cur[1007]={};
		for(int j=1,x;j<=k;j++) scanf("%d",&x),cur[x]=1;
		for(int j=l;j<=r;j++){
			for(int jj=l;jj<=r;jj++){
				if(cur[j]&&!cur[jj]){		//dis[j]>=dis[jj]+1
					add(j,jj,-1);
				}
			}
		}
	}
	for(int i=1;i<=n;i++) if(!dis[i]) dis[i]=1e8;
	int ans=0;
	dis[0]=1;
	for(int i=1;i<=n;i++) add(i,0,0);
	ans=spfa(0)
	if(!ans) puts("Impossible");
	else{
		puts("Possible");
		for(int i=1;i<=n;i++) printf("%d ",dis[i]?dis[i]:233333);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
