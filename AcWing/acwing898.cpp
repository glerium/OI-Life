#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[1007][1007],f[1007][1007];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) scanf("%d",&a[i][j]);
	int ans=-1e8;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
		    if(j==1) f[i][j]=f[i-1][j]+a[i][j];
			else if(j==i) f[i][j]=f[i-1][j-1]+a[i][j];
			else f[i][j]=max(f[i-1][j],f[i-1][j-1])+a[i][j];
		}
	}
	for(int i=1;i<=n;i++) ans=max(f[n][i],ans);
	printf("%d\n",ans);
	return 0;
}
