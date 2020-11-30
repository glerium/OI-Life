#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n;
long long a[maxn],avg,s[maxn];
int main(){
	while(~scanf("%d",&n)){
		avg=0;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),avg+=a[i];
		avg/=n;
		for(int i=1;i<=n;i++) a[i]-=avg,s[i]=s[i-1]+a[i];
		sort(s+1,s+1+n);
		long long mid=(s[(n/2)+1]),ans=0;
		for(int i=1;i<=n;i++) ans+=abs(s[i]-mid);
		printf("%lld\n",ans);
	}
	return 0;
}
