#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=207;
int n,a[maxn],f1[maxn][maxn],f2[maxn][maxn];
int main(){
//	freopen("math.in","r",stdin);
//	freopen("math.out","w",stdout);
	for(int i=1;i<=maxn;i++) for(int j=1;j<=maxn;j++) f1[i][j]=0x3f3f3f3f;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),f1[i][i]=f2[i][i]=a[i];
	for(int k=2;k<=n;k++){
		for(int i=1,j=i+k-1;i<=n&&j<=n;i++,j++){
			for(int t=i;t<=j-1;t++){
				f1[i][j]=min(f1[i][t]+f1[t+1][j]>>1,f1[i][j]);
				f2[i][j]=max(f2[i][t]+f2[t+1][j]>>1,f2[i][j]);
			}
		}
	}
	for(int i=f1[1][n];i<=f2[1][n];i++) printf("%d ",i);
	return 0;
}
