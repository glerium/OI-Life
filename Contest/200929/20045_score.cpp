#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,ord[maxn];
ll t,s[maxn];
struct Task{
	ll a,b,t;
	bool operator<(const Task& rhs)const {return 1.0*b/t>1.0*rhs.b/rhs.t;}
}a[maxn];
template<typename T> void read(T& x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0') {if(ch=='-')w=-1; ch=getchar ();}
	while(ch<='9'&&ch>='0'){v=v*10+ch-'0';ch=getchar ();}
	x=v*w; return;
}
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	read(n),read(t);
	for(int i=1;i<=n;i++) read(a[i].a),read(a[i].b),read(a[i].t);
	if(n<=10){
		for(int i=1;i<=n;i++) ord[i]=i;
		ll ret=0;
		do{
			ll ans=0;
			for(int i=1;i<=n;i++) s[i]=s[i-1]+a[ord[i]].t;
			for(int i=1;i<=n;i++) ans+=a[ord[i]].a-a[ord[i]].b*s[i];
			ret=max(ans,ret);
		}while(next_permutation(ord+1,ord+1+n));
		printf("%lld\n",ret);
	}else{
		sort(a+1,a+1+n);
		ll ans=0;
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i].t;
		for(int i=1;i<=n;i++) ans+=a[i].a-a[i].b*s[i];
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
