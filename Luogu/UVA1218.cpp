#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2e4+10;
int n,cnt,head[maxn],f[maxn][3],ans=0x3fffffff;
//0: is server && father not && son not
//1: not server && father is && son not
//2: not server && only one son is && father not
struct Edge{int to,nxt;}a[maxn<<1];
void add(int x,int y){a[++cnt]=(Edge){y,head[x]};head[x]=cnt;}
void dfs(int x,int fa){
	f[x][0]=1;
	if(!head[x]) f[x][2]=0x3fffffff;
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		dfs(a[i].to,x);
		f[x][0]+=min(f[a[i].to][0],f[a[i].to][1]);
		f[x][1]+=f[a[i].to][2];
	}
	//f[x][1]: sigma: son isn't
	f[x][2]=0x3fffffff;
	for(int i=head[x];i;i=a[i].nxt) f[x][2]=min(f[x][2],f[x][1]-f[a[i].to][2]+f[a[i].to][0]);
}
int main(){
	freopen("test.out","w",stdout);
	while(~scanf("%d",&n)){
		cnt=0; ans=0x3fffffff;
		memset(f,0,sizeof(f));
		memset(head,0,sizeof(head));
		for(int i=1,x,y;i<=n-1;i++){
			scanf("%d%d",&x,&y);
			add(x,y),add(y,x);
		}
		dfs(1,0);
		printf("%d\n",min(f[1][0],f[1][2]));
		int all_last;
		scanf("%d",&all_last);
		if(all_last==-1) break;
	}
}
