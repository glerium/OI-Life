#include <cstdio>
using namespace std;
typedef long long ll;
ll l,r,ans;
bool check(ll x){
	int a[10]={};
	while(x) a[x%10]++,x/=10;
	for(int i=0;i<=9;i++)
		if(i^7&&a[i]==a[7]) return 0;
	return a[7];
}
int main(){
//	freopen("seven.in","r",stdin);
//	freopen("seven1.out","w",stdout);
	scanf("%lld%lld",&l,&r);
	for(ll i=l;i<=r;i++) {ans+=check(i);if(0&check(i)) printf("%d\n",i);}
	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
