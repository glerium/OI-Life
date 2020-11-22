#include <cstdio>
using namespace std;
typedef long long ll;
const int p=5000011;
const int maxn=1e5+10;
int n,k;
ll f[maxn];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<=k;i++) f[i]=(i+1)%p;
	for(int i=k+1;i<=n;i++) f[i]=(f[i-1]+f[i-k-1])%p;
	printf("%lld\n",f[n]);
}
