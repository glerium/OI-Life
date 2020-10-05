#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e6;
typedef long long ll;
int n,q;
ll d[maxn],lim[maxn],f[maxn];

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&d[i]),f[i]=f[i-1]+d[i];
	for(int i=1;i<=n;i++) scanf("%lld",&lim[i]);
	for(int i=1,l,r,x;i<=q;i++){
		ll ans=0;
		scanf("%d%d%d",&l,&r,&x);
		ll xx=x;
		for(int j=l;j<=r;j++){
			for(int k=j;k<=r;k++){
				xx=x;
				bool flag=true;
				for(int t=j;t<=k;t++){
					if(xx+d[t]>lim[t]) xx=lim[t];
					else xx+=d[t];
				}
				ans=max(ans,xx);
			}
		}
		ans=max(ans,x*1ll);
		printf("%lld\n",ans);
	}
	return 0;
}
