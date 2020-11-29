#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=1e9+7;
int t,a,b,h;
ll qpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%p;
		x=x*x%p; y>>=1;
	}
	return ans;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&h);
		if(h==0){
			printf("%d\n",a);
			continue;
		}else if(a==b){
			printf("%lld\n",qpow(a,h+1));
			continue;
		}else if(a==1){
			printf("%lld\n",qpow(b,h));
			continue;
		}else if(b==1){
			printf("%lld\n",1ll*(a-1)*h%p);
			continue;
		}else{
			
		}
	}
}
