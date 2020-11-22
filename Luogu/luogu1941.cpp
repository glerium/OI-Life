#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e4+10,maxm=2e3+10;
const int INF=0x3f3f3f3f;
int n,m,k,x[maxn],y[maxn],l[maxn],h[maxn],f[maxn][maxm];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for(int i=1,x,y,z;i<=k;i++) scanf("%d%d%d",&x,&y,&z),l[x]=y,h[x]=z;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++) f[0][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=x[i]+1;j<=x[i]+m;j++) f[i][j]=min(f[i-1][j-x[i]]+1,f[i][j-x[i]]+1);
		for(int j=m+1;j<=m+x[i];j++) f[i][m]=min(f[i][m],f[i][j]);
		for(int j=1;j<=m-y[i];j++) f[i][j]=min(f[i][j],f[i-1][j+y[i]]);
		if(l[i]) for(int j=1;j<=l[i];j++) f[i][j]=INF;
		if(h[i]) for(int j=h[i];j<=m;j++) f[i][j]=INF;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) printf("%d ",f[i][j]);
//		puts("");
//	}
	int ans=INF;
	for(int i=1;i<=m;i++){
		if(f[n][i]!=-1&&f[n][i]!=INF)
			ans=min(ans,f[n][i]);
	}
	if(ans<INF) printf("1\n%d\n",ans);
	else{
		int i=1,ans=0;
		bool flag[maxn]={};
		for(i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				if(f[i][j]<INF){
					flag[i]=true;
					ans+=bool(h[i]||l[i]);
					break;
				}
			if(!flag[i]) break;
		}
		printf("0\n%d\n",ans);
	}
	return 0;
}
