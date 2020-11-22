#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2e5+10;
int t,n,k,a[maxn][6],mx[6],f[50];
int dfs(int w,int x){
	if(!x) return 0;
	int ans=0;
	for(int i=0;i<=31;i++){
		if((i&w)==i) ans=max(ans,dfs(i,x-1)+f[w^i]);
	}
	return ans;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) scanf("%d",&a[i][j]);
		memset(mx,0,sizeof(mx));
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) mx[j]=max(mx[j],a[i][j]);
		if(k>5){
			int ans=0;
			for(int i=1;i<=5;i++) ans+=mx[i];
			printf("%d\n",ans);
		}else{
			for(int i=1;i<=n;i++){
				for(int j=0;j<=31;j++){
					int cr=0;
					for(int k=0;k<5;k++) if(j&(1<<k)) cr+=a[i][k+1];
					f[j]=max(f[j],cr);
				}
			}
			printf("%d\n",dfs(31,k));
		}
	}
	return 0;
}
