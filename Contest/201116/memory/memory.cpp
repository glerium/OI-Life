#include <cstdio>
using namespace std;
typedef long long ll;
const ll p=1e9+7;
const int maxn=5e6+10;
ll n,m,p2[maxn],sig[maxn],last[maxn],Cn[maxn],ans;
ll qpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%p;
		x=x*x%p, y>>=1;
	}
	return ans;
}
int main(){
	freopen("memory.in","r",stdin);
	freopen("memory.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	p2[0]=1; for(int i=1;i<=m;i++) p2[i]=p2[i-1]*2%p;
	for(int i=1;i<=m;i++) sig[i]=(p2[i]-1)%p;
	sig[m]=(p2[m]-1+p)%p; last[m]=1;
	for(int i=m+1;i<=n;i++) last[i]=last[i-1]*i%p*qpow(i-m,p-2)%p;
	Cn[0]=1; for(int i=1;i<=n;i++) Cn[i]=Cn[i-1]*(n-i+1)%p*qpow(i,p-2)%p;
	for(int i=m+1;i<=n;i++){
		sig[i]=(sig[i-1]*2-last[i-1]+1)%p;
	}
	for(int i=1;i<=n;i++) ans=(ans+sig[i]*Cn[i])%p;
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
