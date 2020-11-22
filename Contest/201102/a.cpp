#include <cstdio>
#include <algorithm>
using namespace std;
unsigned long long f[1000];
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	f[1]=1;
	for(int i=2;i<=80;i++) f[i]=f[i-1]*2+f[i-2];
	int t;
	scanf("%d",&t);
	while(t--){
		long long n; scanf("%lld",&n);
		for(int i=1;;i++){
			if(f[i]>=n){
				printf("%lld\n",f[i]==n?f[i]:f[i-1]);
				break;
			}
		}
	}
	return 0;
}
