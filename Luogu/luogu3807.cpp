#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,m,p;
ll fac[maxn];
ll qpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%p;
		x=x*x%p, y>>=1;
	}
	return ans;
}
ll C(ll x,ll y){
	if(x<y) return 0; 
//	printf("---%lld\n",fac[x]*qpow(fac[y],p-2)%p*qpow(fac[x-y],p-2)%p);
	return fac[x]*qpow(fac[y],p-2)%p*qpow(fac[x-y],p-2)%p;
}
ll lucas(ll x,ll y){
//	printf(":%lld %lld\n",x,y);
	if(!x||!y) return 1;
	return C(x%p,y%p)*lucas(x/p,y/p)%p;
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&p);
		fac[0]=1; for(int i=1;i<=n+m;i++) fac[i]=fac[i-1]*i%p;
		printf("%lld\n",lucas(n+m,n)%p);
	}
	return 0;
}
