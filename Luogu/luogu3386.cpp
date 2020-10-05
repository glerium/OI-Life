#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e3+10,maxm=1e5+10;
int nl,nr,m,cnt,head[maxn],ans,matchl[maxn],matchr[maxn];
bool check[maxn];
struct Edge{
	int to,nxt;
}a[maxm];
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
bool dfs(int x){
	for(int i=head[x];i;i=a[i].nxt){
		if(!check[a[i].to]){
			check[a[i].to]=true;
			if(!matchr[a[i].to]||dfs(matchr[a[i].to])){
				matchl[x]=a[i].to;
				matchr[a[i].to]=x;
				return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d%d%d",&nl,&nr,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=nl;i++){
		if(!matchl[i]){
			memset(check,0,sizeof(check));
			if(dfs(i)) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
