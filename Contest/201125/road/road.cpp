#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
const ll p=1e9+7;
int n,a[maxn];
template<typename T>void read(T& x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	ll ans1=0;
	for(int i=1;i<=n;i++)
		if(a[i]>a[i-1]) ans1+=a[i]-a[i-1];
	printf("%lld\n",ans1);
	bool isp=true,isle=true;
	for(int i=1;i<n;i++) isp&=(a[i]==a[i+1]);
	for(int i=1;i<n;i++) isle&=(a[i]<=a[i+1]);
	if(isp){
		printf("%lld\n%lld\n",1ll*n*n*a[1],1ll*n*n*a[1]);
		return 0;
	}else if(isle){
		ll ans2=0,ans3=0;
		for(int i=1;i<=n;i++) ans2+=1ll*(n+1-i)*(n+1-i)*(a[i]-a[i-1]);
		printf("%lld\n%lld\n",ans2,ans2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
