#include <cstdio>
#include <cstring>
const int maxn=2e3+10;
int n,m,cnt,head[maxn],match[maxn];
bool check[maxn],have[maxn];
struct Edge{
	int to,nxt;
}a[maxn];
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
bool dfs(int x){
	for(int i=head[x];i;i=a[i].nxt){
		if(!check[a[i].to]){
			check[a[i].to]=true;
			if(!match[a[i].to]||dfs(match[a[i].to])){
				match[a[i].to]=x;
				match[x]=a[i].to;
				return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		have[x]=true,have[y+n]=true;
		add(x,y+n);
	}
	int ans=2*n;
	for(int i=1;i<=n;i++){
		memset(check,0,sizeof(check));
		if(dfs(i)) ans--;
	}
	printf("%d\n",ans*n);
	return 0;
}
