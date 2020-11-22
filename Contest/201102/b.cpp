#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e4+10;
const int p=998244853;
int n,k;
ll a[maxn],c[maxn],pt[maxn];
ll qpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%p;
		x=x*x%p; y>>=1;
	}
	return ans;
}
ll f(ll x){
	ll ans=a[k+1];
	for(int i=k;i>=1;i--)
		ans=(ans*x+a[i])%p;
	return ans;
}
int main(){
	freopen("b.in","r",stdin); freopen("b.out","w",stdout);
//	scanf("%d",&k);
//	for(int i=1;i<=k+1;i++) scanf("%lld",&a[i]);
//	while(1){
//		ll x; scanf("%lld",&x);
//		printf("%lld\n",f(x));
//	}
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k+1;i++) scanf("%lld",&a[i]);
	c[0]=1; for(int i=1;i<=n;i++) c[i]=c[i-1]*(n-i+1)*qpow(i,p-2)%p;
	pt[0]=1; for(int i=1;i<=n;i++) pt[i]=pt[i-1]*2%p;
	ll ans=0; for(int i=0;i<=n;i++) ans=(ans+c[i]*pt[n-i]%p*f(i)%p)%p;
	printf("%lld\n",ans);
	return 0;
}
