#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T>void read(T& x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
ll s;
int main(){
//	freopen("hard.in","r",stdin);
//	freopen("hard.out","w",stdout);
//	read(s);
	s=1000000;
	ll ans=1e18;
	for(ll a=1;a<=s;a++){
		if(a*a+a*a>s) break;
		for(ll b=a;b<=s;b++){
			if(a*b+b*b>s) break;
			for(ll c=sqrt(s-a*b);c>=b;c--){
				if((s-a*b)%c!=0) continue;
				ll d=(s-a*b)/c;
				ans=min(ans,2*(a+b+c+d));
//				printf("%lld %lld %lld %lld: %lld\n",a,b,c,d,2*(a+b+c+d));
				break;
			}
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}	
