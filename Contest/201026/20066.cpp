#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,m;
int main(){
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	scanf("%d%d",&n,&m);
	int buf[n+10][m+10],v[n+10][m+10],f[n+10][m+10];
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&buf[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&v[i][j]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=max(f[i-1][j],f[i][j-1])+v[i][j];
		}
	}
	printf("%d\n",f[n][m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
