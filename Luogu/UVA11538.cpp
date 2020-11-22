#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
long long ans;
int main(){
	while(~scanf("%d%d",&n,&m)&&(n||m)){
		ans=0;
		if(n>m) swap(n,m);
		ans=1ll*n*m*(m-1)/2+1ll*m*n*(n-1)/2;
		for(int i=1;i<=n;i++) ans+=2ll*i*(i-1);
		ans+=(m-n-1ll)*n*(n-1);
		ans*=2ll;
		printf("%lld\n",ans);
	}
	return 0;
}
