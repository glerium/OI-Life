#include <cstdio>
using namespace std;
typedef long long ll;
ll a,b,c,d,ans;
const ll p=1e9+7;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int main(){
//	freopen("hacker.in","r",stdin);
//	freopen("hacker.out","w",stdout);
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	for(ll i=a;i<=b;i++){
		for(ll j=c;j<=d;j++){
			ll k=gcd(i,j);
//			if(i/k+j/k>999) continue;
			ans=(ans+i/k+j/k)%p;
		}
	}
	printf("%lld\n",ans%p);
	return 0;
}
