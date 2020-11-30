#include <bits/stdc++.h>
using namespace std;
const int maxn=107;
int n,m,a[maxn][maxn],f[maxn][maxn][maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	int ans=0;
	for(int k=1;k<=m+n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				f[k][i][j]=max(max(f[k-1][i][j],f[k-1][i-1][j]),max(f[k-1][i][j-1],f[k-1][i-1][j-1]))+a[i][k-i]+a[j][k-j];
				ans=max(ans,f[k][i][j]);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
