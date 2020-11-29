#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m,k,f[maxn][maxn][8],f2[maxn][maxn][8];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&f[i][j][0]),f2[i][j][0]=f[i][j][0];
	int sz=log2(k+0.1);
	for(int r=1;r<=sz;r++){
		for(int i=1;i+(1<<r)-1<=n;i++){
			for(int j=1;j+(1<<r)-1<=m;j++){
				f[i][j][r]=max(max(f[i][j][r-1],f[i+(1<<r-1)][j][r-1]),max(f[i][j+(1<<r-1)][r-1],f[i+(1<<r-1)][j+(1<<r-1)][r-1]));
				f2[i][j][r]=min(min(f2[i][j][r-1],f2[i+(1<<r-1)][j][r-1]),min(f2[i][j+(1<<r-1)][r-1],f2[i+(1<<r-1)][j+(1<<r-1)][r-1]));
//				printf("f[%d][%d][%d]=%d\n",i,j,r,f2[i][j][r]);
			}
		}
	}
	int ans=1e8;
	for(int i=1;i+k-1<=n;i++){
		for(int j=1;j+k-1<=m;j++){
			int mx=0,mi=1e8;
			mx=max(max(f[i][j][sz],f[i+k-(1<<sz)][j][sz]),max(f[i][j+k-(1<<sz)][sz],f[i+k-(1<<sz)][j+k-(1<<sz)][sz]));
			mi=min(min(f2[i][j][sz],f2[i+k-(1<<sz)][j][sz]),min(f2[i][j+k-(1<<sz)][sz],f2[i+k-(1<<sz)][j+k-(1<<sz)][sz]));
			ans=min(ans,mx-mi);
//			printf("%d %d: %d, %d\n",i,j,mx,mi);
		}
	}
	printf("%d\n",ans);
	return 0;
}
