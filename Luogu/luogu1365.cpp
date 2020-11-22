#include <cstdio>
using namespace std;
const int maxn=5e5+10;
int n;
double f[maxn],a[maxn];
char s[maxn];
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='x') f[i]=f[i-1],a[i]=0;
		else if(s[i]=='o') f[i]=f[i-1]+2*a[i-1]+1,a[i]=a[i-1]+1;
		else f[i]=f[i-1]*0.5+(f[i-1]+2*a[i-1]+1)*0.5,a[i]=(a[i-1]+1)*0.5;
	}
	printf("%.4lf\n",f[n]);
	return 0;
}
