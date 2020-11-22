#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a,b,c,d;
const ll p=1e9+7;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int main(){
	freopen("hacker.in","r",stdin);
	freopen("hacker.out","w",stdout);
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	ll ans=0;
	for(ll x=1;x<=999;x++){
		for(ll y=1;y<=999-x;y++){
			if(gcd(x,y)!=1) continue;
			ll ss=c*x/y+bool(c*x%y);
			ll tt=d*x/y;
			if(ss>tt) continue;
//			printf("%lld %lld %lld %lld\n",x,y,ss,tt);
			ll r=min(b,tt),l=max(a,ss);
			if(l>r) continue;
			ll aaa=l/x+bool(l%x);
			ll bbb=r/x;
			ans=(ans+(bbb-aaa+1)*(x+y))%p;
//			printf("deb:%lld %lld\n",aaa,bbb);
//			printf("+%lld\n",(bbb-aaa+1)*(x+y));
		}
	}
	printf("%lld\n",ans%p);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
