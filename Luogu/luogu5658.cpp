#include <cstdio>
using namespace std;
const int maxn=1e6+10;
int n,head[maxn],cnt,st[maxn],top,fa[maxn];
long long f[maxn],ans[maxn];
char c[maxn];
struct Edge{
	int to,nxt;
}a[maxn];
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
void dfs(int x,int from){
	fa[x]=from;
	int tmp=0;
	if(c[x]==')'&&top){
		tmp=st[top];
		top--;
		f[x]=f[fa[tmp]]+1;
	}else if(c[x]=='(') st[++top]=x;
	ans[x]=ans[fa[x]]+f[x];
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==from) continue;
		dfs(a[i].to,x);
	}
	if(tmp) st[++top]=tmp;
	else if(top) top--;
}
int main(){
	scanf("%d%s",&n,c+1);
	for(int i=2,x;i<=n;i++){
		scanf("%d",&x);
		add(i,x),add(x,i);
	}
	dfs(1,0);
	long long final=0;
	for(int i=1;i<=n;i++) final^=1ll*i*ans[i];
	printf("%lld\n",final);
	return 0;
}
