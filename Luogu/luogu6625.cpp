#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[100007],f[100007];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),f[i]=f[i-1]+a[i];
	long long ans=0,aa=0;
	for(int i=2;i<=n;i++)
		if(f[i]>=0) ans+=f[i];
	printf("%lld\n",ans);
	return 0;
}
