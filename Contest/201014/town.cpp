#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
int n;
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	scanf("%d",&n);
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i*i+j*j>n*n) continue;
			ll k=sqrt(i*i+j*j);
			if(k*k!=i*i+j*j) cnt++;
		}
	}
	printf("%lld\n",cnt*4);
	fclose(stdin);
	fclose(stdin);
	return 0;
}
