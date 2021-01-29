#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,t;
long long p[maxn];
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int main(){
	while(~scanf("%d%d",&n,&t)){
		p[0]=1; for(int i=1;i<=n;i++) p[i]=p[i-1]*t;
		long long ans=0;
		for(int i=0;i<=n-1;i++) ans+=p[gcd(n,i)];
		if(n&1) printf("%lld %lld\n",ans/n,(ans+n*p[(n+1)/2])/(2*n));
		else printf("%lld %lld\n",ans/n,(ans+n*(p[n/2]+p[n/2+1])/2)/(2*n));
	}
	return 0;
}
