#include <cstdio>
using namespace std;
int n;
int main(){
	long long a1=1;
	scanf("%d",&n);
	for(int i=n+2;i<=2*n;i++) a1*=i;
	for(int i=1;i<=n;i++) a1/=i;
	printf("%lld\n",a1);
}
