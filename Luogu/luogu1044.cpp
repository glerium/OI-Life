#include <cstdio>
using namespace std;
long long f[50];
long long g(int x){
	if(f[x]) return f[x];
	long long ans=0;
	for(int i=0;i<=x-1;i++) ans+=g(i)*g(x-i-1);
	return f[x]=ans;
}
int main(){
	f[0]=f[1]=1;
	int n;
	scanf("%d",&n);
	printf("%lld\n",g(n));
	return 0;
}
