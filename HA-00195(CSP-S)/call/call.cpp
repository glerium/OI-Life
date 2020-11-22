#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int p=998244353;
int n,m,q,head[maxn],cnt,f[maxn];
ll a[maxn],shiji[maxn];
struct Call{
	int to,nxt;
}g[maxn];
struct Function{
	int op,x,y;
}t[maxn];
template<typename T>void read(T&x){
	T v=0,w=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar();
	x=v*w; return;
}
ll dfs1(int x){
	if(shiji[x]) return shiji[x];
	ll ans=0;
	for(int i=head[x];i;i=g[i].nxt)
		ans=(ans+dfs1(g[i].to))%p;
	return shiji[x]=ans;
}
ll dfs2(int x){
	if(shiji[x]!=1) return shiji[x];
	ll ans=t[x].x;
	for(int i=head[x];i;i=g[i].nxt)
		ans=(ans*dfs2(g[i].to))%p;
	return shiji[x]=ans;
}
void add(int x,int y){
	g[++cnt]=(Call){y,head[x]};
	head[x]=cnt;
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	read(m);
	int sigma_c=0;
	bool aru1=false,aru2=false;
	for(int i=1;i<=m;i++){
		read(t[i].op),read(t[i].x);
		if(t[i].op==1) read(t[i].y),aru1=true;
		else if(t[i].op==3){
			sigma_c+=t[i].x;
			int x,y; read(x);
			while(x--){
				read(y);
				add(i,y);
			}
		}else aru2=true;
	}
	read(q);
	for(int i=1;i<=q;i++) read(f[i]);
	if(!aru2){	//addition only
		for(int i=1;i<=m;i++) dfs1(i);
		
	}else if(!aru1){	//multiplation only
		for(int i=1;i<=m;i++) shiji[i]=1;
		for(int i=1;i<=m;i++) dfs2(i);
		ll final=1;
		for(int i=1;i<=q;i++) final=(final*shiji[f[i]])%p;
		for(int i=1;i<=n;i++) a[i]=(a[i]*final)%p;
		for(int i=1;i<=n;i++) printf("%lld ",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
