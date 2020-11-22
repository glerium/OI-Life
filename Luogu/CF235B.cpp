#include <cstdio>
using namespace std;
const int maxn=1e5+10;
int n;
double p[maxn],a[maxn],b[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf",&p[i]);
	for(int i=1;i<=n;i++){
		a[i]=(a[i-1]+1)*p[i];
		b[i]=b[i-1]*(1-p[i])+(b[i-1]+a[i-1]*2+1)*p[i];
	}
	printf("%.20lf\n",b[n]);
	return 0;
}
