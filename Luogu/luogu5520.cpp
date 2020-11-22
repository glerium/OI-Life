#include <cstdio>
using namespace std;
typedef long long ll;
ll n,m,p;
int main(){
	scanf("%*d%lld%lld%lld",&n,&m,&p);
	ll ans=1;
	for(ll i=n-2*m+3;i<=n-m+1;i++) ans=ans*i%p;
	printf("%lld\n",ans);
	return 0;
}
