#include <cstdio>
using namespace std;
const int maxn=1e5+10;
int n;
double p[maxn],a[maxn],b[maxn],f[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf",&p[i]);
	for(int i=1;i<=n;i++){
		a[i]=(a[i-1]+1)*p[i];
		b[i]=(b[i-1]+2*a[i-1]+1)*p[i];
		f[i]=(f[i-1]+3*b[i-1]+3*a[i-1]+1)*p[i]+f[i-1]*(1-p[i]);
	}
	printf("%.1lf\n",f[n]);
	return 0;
}
