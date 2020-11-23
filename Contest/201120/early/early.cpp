#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=2e5+10;
const int p=1e9+7;
int n,m,q,head[maxn],cnt,in[maxn],ct,v[maxn],rank[maxn],f[maxn],tmp[maxn],kkk[maxn];
struct Edge{
	int to,nxt;
}a[maxn];
bool cmp(int rhs,int lhs){
	return rank[rhs]<rank[lhs];
}
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
void topo(){
	queue<int> q;
	for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
	while(!q.empty()){
		int t=q.front();q.pop();
		rank[t]=ct;
		for(int i=head[t];i;i=a[i].nxt){
			in[a[i].to]--;
			if(in[a[i].to]==0) q.push(a[i].to);
		}
	}
}
int dfs(int x){
	f[kkk[x]]=1;
	for(int i=head[x];i;i=a[i].nxt){
		dfs(a[i].to);
		f[kkk[x]]+=f[kkk[a[i].to]];
	}
	return f[x];
}
int main(){
	freopen("early.in","r",stdin);
	freopen("early.out","w",stdout);
	read(n),read(m);
	for(int i=1,x,y;i<=m;i++) read(x),read(y),add(x,y),in[y]++;
	topo();
	read(q);
	for(int i=1,x;i<=q;i++){
		read(x);
		for(int j=1;j<=x;j++) read(v[j]),kkk[v[j]]=j;
		sort(v+1,v+1+x,cmp);
		dfs(v[1]);
		long long ans=0;
		for(int j=1;j<=x;j++) ans+=j*f[j];
		for(int j=1;j<=x;j++) ans-=(x+1-j)*f[j];
		printf("%lld\n",ans);
	}
	return 0;
}
