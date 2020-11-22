#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e7+10;
int n,od[maxn],pre[maxn],nxt[maxn],head;
ll a[maxn],ta[maxn];
template<typename T> void read(T& x){
	T v=0,w=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') w=-1; ch=getchar();}
	while(ch<='9'&&ch>='0'){v=v*10+ch-'0'; ch=getchar();}
	x=v*w; return;
}
ll del(int x){
	ll ans=a[pre[x]]*a[nxt[x]]*a[x];
	pre[nxt[x]]=pre[x];
	nxt[pre[x]]=nxt[x];
	if(x==head) head=nxt[x];
	return ans;
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	if(n<=10){
		for(int i=1;i<=n;i++) od[i]=i;
		ll ans=0;
		memset(&ans,0x7f,sizeof(ans));
		a[0]=a[n+1]=1;
		do{
			for(int i=1;i<=n;i++) pre[i]=i-1,nxt[i]=i+1;
			head=1;
			ll ret=0;
			for(int i=1;i<n;i++) ret+=del(od[i]);
			ret+=a[od[n]];
			ans=min(ans,ret);
		}while(next_permutation(od+1,od+1+n));
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
