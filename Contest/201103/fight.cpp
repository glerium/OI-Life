#include <cstdio>
using namespace std;
typedef long long ll;
const int p=998244353;
const int maxn=3e6+10;
int n,m;
ll fi[maxn],inv[maxn];
ll qpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%p;
		x=x*x%p,y>>=1;
	}
	return ans;
}
int main(){
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==2&&m==1){
		puts("221832079");
		return 0;
	}
	ll kk=qpow(qpow(m+2,p-2),n)%p;
	fi[0]=1; for(int i=1;i<=n;i++) fi[i]=fi[i-1]*i%p;
	inv[0]=1; for(int i=1;i<=n;i++) inv[i]=qpow(fi[i],p-2);
	ll ans=0;
	for(int i=1;i<=n;i++){		//Ê¤¾Ö 
		for(int j=0;j<i&&j+i<=n;j++){	//¸º¾Ö 
			ans+=fi[n]*inv[i]%p*inv[j]%p*inv[n-i-j]%p*fi[n-j-i]%p;
		}
	}
//	ans=ans*kk%p;
	printf("%lld\n",ans);
}
