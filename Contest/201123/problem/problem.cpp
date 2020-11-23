#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=2e6+10;
int n,r,head[maxn],cnt;
ll x,dis[maxn];
bool vis[maxn];
struct Edge{
	int to;
	ll dis;
	int nxt;
}a[maxn];
struct State{
	int x;
	ll dis;
	bool operator<(const State& rhs)const{return dis>rhs.dis;}
};
priority_queue<State> q;

void add(int x,int y,ll z){
	a[++cnt]=(Edge){y,z,head[x]};
	head[x]=cnt;
}

template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}

int main(){
	freopen("problem.in","r",stdin);
	freopen("problem.out","w",stdout);
	int em=0;
	read(n),read(r),read(em),read(x);
	for(int i=1;i<=2*n;i++) read(em);
	for(int i=1,x,y,z;i<=r;i++){
		read(x),read(y),read(z);
		add(x,y,z),add(y,x,z);
	}
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	q.push((State){1,0});
	while(!q.empty()){
		State now=q.top(); q.pop();
		if(vis[now.x]) continue;
		vis[now.x]=true;
		for(int i=head[now.x];i;i=a[i].nxt){
			if(dis[a[i].to]>dis[now.x]+a[i].dis){
				dis[a[i].to]=dis[now.x]+a[i].dis;
				q.push((State){a[i].to,dis[a[i].to]});
			}
		}
	}
	for(int i=1;i<=n;i++) printf("%lld ",i==1?0:dis[i]+x);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
