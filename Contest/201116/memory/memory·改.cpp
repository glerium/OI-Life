#include <cstdio>
using namespace std;
typedef long long ll;
const ll p=1e9+7;
const int maxn=5e6+10;
ll n,m,c[maxn];
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
	c[0]=1; for(int i=1;i<=m;i++) c[i]=c[i-1]*(n-i+1)%p*qpow(i,p-2)%p;	//c[i]=C(n-i,n)
	ll ans=0;
	for(int i=1;i<=m;i++) ans=(ans+c[i]*qpow(2,n-i)%p)%p;
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
