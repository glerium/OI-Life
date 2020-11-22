#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll l,r,ans;
ll ff[10]={1e0,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9};
bool hs[100000100];
bool check(ll x){
	int dig=log10(x);
	if(ff[dig+1]<=x) dig++;
	ll rx=x;
	if(x>10 && !hs[x%ff[dig]] && (x/ff[dig])!=7){
		hs[x]=0;
		return false;
	}
	int a[10]={};
	while(x) a[x%10]++,x/=10;
	if(x<=1e8) hs[rx]=a[7];
	for(int i=0;i<=9;i++)
		if(i^7&&a[i]==a[7]) return 0;
	return a[7];
}
int main(){
//	freopen("seven.in","r",stdin);
//	freopen("seven.out","w",stdout);
	scanf("%lld%lld",&l,&r);
	for(int i=1;i<=l;i++) check(i);
	for(ll i=l;i<=r;i++) ans+=check(i);
	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
