#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e4+10;
int n,w,s;
ll a[maxn],f[maxn][maxn],q[maxn],tp;
int main(){
	scanf("%d%d%d",&n,&w,&s);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) for(int j=0;j<=w;j++) f[i][j]=-1e18;
	/* equation: f[i][j]=max_(0<=k<=s)^{f[i-1][j-k]+j*a[i]} */
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(i,w);j++){
			for(int k=j-1;k<=min(w,j+s-1);k++)
				f[i][j]=max(f[i-1][k]+j*a[i],f[i][j]);
		}
	}
	ll ans=-1e16;
	for(int i=1;i<=w;i++) ans=max(ans,f[n][i]);
	printf("%lld\n",ans);
	return 0;
}
