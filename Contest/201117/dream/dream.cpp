#include <cstdio>
using namespace std;
typedef long long ll;
const ll p=998244353;
ll qpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%p;
		x=x*x%p; y>>=1;
	}
	return ans;
}
int main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
