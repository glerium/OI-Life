#include <cstdio>
using namespace std;
const int maxn=1e5+10;
int n,m;
long long f[maxn];
int main(){
	scanf("%d",&n);
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
			f[j]=(f[j]+f[j-i])%2147483648;
	}
	printf("%d\n",f[n]-1);
	return 0;
}
