#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int n,m;
ll f[maxn];
template<typename T>void read(T& x){
	T v=0,w=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar();
	x=v*w;return;
}
int lowbit(int x){return x&-x;}
void add(ll x,int k){
	while(k<=n){
		f[k]+=x;
		k+=lowbit(k);
	}
}
ll query(int x){
	ll ans=0;
	while(x){
		ans+=f[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	read(n),read(m);
	for(int i=1,x;i<=n;i++){
		read(x);
		add(x,i);
	}
	for(int i=1,op,x,y;i<=m;i++){
		read(op),read(x),read(y);
		if(op==1) add(y,x);
		else printf("%lld\n",query(y)-query(x-1));
	}
	return 0;
}
