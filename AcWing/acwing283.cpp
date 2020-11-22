#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn],cnt,in[maxn],head[maxn],f[maxn][2];
struct Edge{
	int to,nxt;
}t[maxn];
void add(int x,int y){
	t[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
void dfs(int x){
	f[x][0]=0;
	f[x][1]=a[x];
	for(int i=head[x];i;i=t[i].nxt){
		dfs(t[i].to);
		f[x][1]+=f[t[i].to][0];
		f[x][0]+=max(f[t[i].to][0],f[t[i].to][1]);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,x,y;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		add(y,x);
		in[x]++;
	}
	int root;
	for(int i=1;i<=n;i++){
		if(!in[i]) root=i;
		f[i][0]=f[i][1]=-1e8;
	}
	dfs(root);
	printf("%d\n",max(f[root][0],f[root][1]));
	return 0;
}
