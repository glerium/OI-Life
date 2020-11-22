#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=207;
const int base=maxn;
int t,n,m,p[maxn],d[maxn],f[maxn][maxn][maxn<<1];
struct Step{
	int x,y,z;
}fw[maxn][maxn][maxn<<1];
int main(){
	scanf("%d%d",&n,&m);
	for(int kase=1;n&&m;kase++){
		for(int i=1;i<=n;i++) scanf("%d%d",&p[i],&d[i]);
		for(int i=1;i<=n;i++) f[i][0][base]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++){
				for(int k=maxn<<1;k>=p[i]-d[i];k--){
					fw[i][j][k]=(Step){i-1,j,k};
					f[i][j][k]=f[i-1][j][k];
					if(j<1||k-p[i]+d[i]<0) continue;
					if(f[i][j][k]>f[i-1][j-1][k-p[i]+d[i]]+p[i]+d[i]){
						f[i][j][k]=f[i-1][j-1][k-p[i]+d[i]]+p[i]+d[i];
						fw[i][j][k]=(Step){i-1,j-1,k-p[i]+d[i]};
					}
				}
			}
		}
		for(int i=0;i<base;i++){
			if(f[n][m][i+base]||f[n][m][base-i]) printf("%d %d\n",f[n][m][i+base],f[n][m][base-i]);
		}
		printf("Jury #%d\n",kase);
		puts("\n");
		scanf("%d%d",&n,&m);
	}
}
