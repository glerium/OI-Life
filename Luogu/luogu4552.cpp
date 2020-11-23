#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn],c[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),c[i]=a[i]-a[i-1];
	long long x=0,y=0;
	for(int i=2;i<=n;i++){
		if(c[i]>0) x+=c[i];
		else y-=c[i];
	}
	printf("%lld\n%lld\n",min(x,y)+abs(x-y),abs(x-y)+1);
	return 0;
}
