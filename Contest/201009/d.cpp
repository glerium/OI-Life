#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int p=1004535809;
int n,a[maxn],f[maxn],ct[maxn],idx;
ll pow2[maxn];

template<typename T> void read(T& x){
	T v=0,w=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') w=-1; ch=getchar();}
	while(ch<='9'&&ch>='0'){v=v*10+ch-'0'; ch=getchar();}
	x=v*w; return;
}
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll lcm(ll x,ll y){return x*y/gcd(x,y);}

int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			f[++idx]=a[i];
			ct[idx]=1;
		}else ct[idx]++;
	}
	pow2[0]=1;
	for(int i=1;i<=n;i++) pow2[i]=pow2[i-1]*2%p;
	ll ans=0;
	for(ll i=0;i<(1<<idx);i++){
		ll cur=1,curcnt=1;
		for(int j=1;j<=idx;j++) if((i>>(j-1))&1) cur=lcm(cur,f[j]),curcnt=curcnt*(pow2[ct[j]]-1)%p;
		cur=cur*curcnt%p;
		ans=(ans+cur*curcnt)%p;
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
