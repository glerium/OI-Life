#include <cstdio>
using namespace std;
const int p=10007;
typedef long long ll;
int a,b,n,m,k;
int qpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=1ll*ans*x%p;
		x=1ll*x*x%p;
		y>>=1;
	}
	return ans;
}
int main(){
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
	ll ans=1;
	for(int i=1;i<=n;i++) ans=ans*a%p;
	for(int i=1;i<=m;i++) ans=ans*b%p;
	for(int i=1;i<=k;i++) ans=ans*i%p;
	for(int i=1;i<=m;i++) ans=ans*qpow(i,p-2)%p;
	for(int i=1;i<=n;i++) ans=ans*qpow(i,p-2)%p;
	printf("%lld\n",ans);
	return 0;
}
