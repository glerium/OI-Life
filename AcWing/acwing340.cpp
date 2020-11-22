#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=2e6+10;
int n,p,k,cnt,head[maxn],v[maxn];
ll dis[maxn];
struct Edge{
	int to;
	ll dis;
	int nxt;
}a[maxn*10];
struct State{
	int id;
	ll dis;
	bool operator<(const State& rhs)const{return dis>rhs.dis;}
};
priority_queue<State> q;
void add(int x,int y,int z){
	a[++cnt]=(Edge){y,z,head[x]};
	head[x]=cnt;
}
int main(){
	scanf("%d%d%d",&n,&p,&k);
	for(int i=1,x,y,z;i<=p;i++){
		scanf("%d%d%d",&x,&y,&z);
		for(int j=0;j<=k;j++) add(x+n*j,y+n*j,z),add(y+n*j,x+n*j,z);
		for(int j=0;j<k;j++) add(x+n*j,y+n*(j+1),0),add(y+n*j,x+n*(j+1),0);
	}
	memset(dis,0x3f,sizeof(dis));
	q.push((State){1,0});
	v[1]=true; dis[1]=0;
	while(!q.empty()){
		State cur=q.top();
		q.pop(); v[cur.id]=false;
		for(int i=head[cur.id];i;i=a[i].nxt){
			if(dis[a[i].to]>max(dis[cur.id],a[i].dis)){
				dis[a[i].to]=max(dis[cur.id],a[i].dis);
				if(!v[a[i].to]) q.push((State){a[i].to,dis[a[i].to]}),v[a[i].to]=true;
			}
		}
	}
	long long ans=1e15;
	for(int i=1;i<=k+1;i++) ans=min(ans,dis[n*i]);
	printf("%lld\n",ans!=1e15?ans:-1);
	return 0;
}
