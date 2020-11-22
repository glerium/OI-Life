#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll p=998244353;
int n,k;
ll w[maxn],s,f[maxn],ans;
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar ();
	x=v*w; return;
}
ll qpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%p;
		x=x*x%p;y>>=1;
	}
	return ans;
}
int main(){
	freopen("ichigo.in","r",stdin);
	freopen("ichigo.out","w",stdout);
	read(n),read(k);
	for(int i=1;i<=n;i++) read(w[i]),w[i]%=p;
	if(k==1||n==k){
		sort(w+1,w+1+n,greater<int>());
		ll ans=0;
		for(int i=1;i<=n-k+1;i++) ans=(ans+w[i])%p;
		ans=ans*(n-k+1)%p;
		for(int i=n-k+2;i<=n;i++) ans=(ans+w[i])%p;
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<=n;i++) s=(s+w[i])%p;
	f[1]=1;
	for(int i=2;i<=n-k+1;i++) f[i]=f[i-1]*(n-i+1)%p*qpow(i-1,p-2)%p;
//	for(int i=1;i<=n-k+1;i++) printf(": %lld\n",f[i]);
	for(int i=1;i<=n-k+1;i++) ans=(ans+f[i]*i)%p;
	ans=ans*s%p;
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
