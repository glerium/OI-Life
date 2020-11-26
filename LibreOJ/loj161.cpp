#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=3e6+10;
int n,p;
ll inv[maxn];
int main(){
	scanf("%d%d",&n,&p);
	inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=(p-p/i)*inv[p%i]%p;
	for(int i=1;i<=n;i++) printf("%lld\n",inv[i]);
	return 0;
}
