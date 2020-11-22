#include <cstdio>
using namespace std;
typedef long long ll;
const ll p=10000007;
ll n,f[107][107],t[107];
ll qpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%p;
		x=x*x%p; y>>=1;
	}
	return ans;
}
ll dp(int n,int m){
	if(m>n||!n||m<0) return 0;
	if(f[n][m]) return f[n][m];
	if(n==m||!m) return f[n][m]=1;
	return f[n][m]=dp(n-1,m)+dp(n-1,m-1);
}
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=60;i++) for(int j=1;j<=60;j++) dp(i,j); 
	int ct=0;
	for(ll i=60;i>=0;i--){
		if(n&(1ll<<i)){
			for(int j=1;j<=i;j++)
				t[ct+j]+=f[i][j];
			t[++ct]++; 
		}
	}
	ll ans=1;
	for(int i=1;i<=60;i++) ans=ans*qpow(i,t[i])%p;
	printf("%lld\n",ans);
	return 0; 
}
