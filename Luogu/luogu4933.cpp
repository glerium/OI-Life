#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e3+10,maxm=4e4+10;
const int TS=2e4+2;
const int p=998244353;
int n,a[maxn],f[maxn][maxm];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			f[i][a[i]-a[j]+TS]=(f[i][a[i]-a[j]+TS]+f[j][a[i]-a[j]+TS]+1)%p;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<maxm;j++)
			ans=(ans+f[i][j])%p;
	}
	printf("%d\n",ans+n);
	return 0;
}
