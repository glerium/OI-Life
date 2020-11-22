#include <cstdio>
using namespace std;
const int maxn=1e5+10;
int n,a,b,c;
long long x[maxn];
int main(){
	freopen("sunny.in","r",stdin);
	freopen("sunny.out","w",stdout);
	scanf("%d%d%d%d",&n,&a,&b,&c);
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
	long long ans=0,sum=0;
	for(int i=1;i<=n;i++) sum+=x[i]*x[i]*a+b*x[i]+c;
	printf("%lld\n",sum);
	return 0;
}
