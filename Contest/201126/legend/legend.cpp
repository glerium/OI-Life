#include <cstdio>
using namespace std;
typedef long long ll;
const ll p=998244353;
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')v=v*10+ch-'0',ch=getchar();
	x=v*w; return;
}
ll qpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%p;
		x=x*x%p,y>>=1;
	}
	return ans;
}
int main(){
//	freopen("legend.in","r",stdin);
//	freopen("legend.out","w",stdout);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
