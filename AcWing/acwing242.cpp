#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,m;
ll t[maxn],a[maxn];
void getop(char& x){
	char ch=getchar();
	while(ch!='C'&&ch!='Q') ch=getchar();
	x=ch;
}
int lowbit(int x){return x&-x;}
void add(int x,int k){
	while(x<=n){
		t[x]+=k;
		x+=lowbit(x);
	}
}
ll query(int x){
	ll ans=0;
	while(x){
		ans+=t[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) add(i,a[i]-a[i-1]);
	char op; int x,y,k;
	for(int i=1;i<=m;i++){
		getop(op);
		scanf("%d",&x);
		if(op=='C'){
			scanf("%d%d",&y,&k);
			add(x,k),add(y+1,-k);
		}else printf("%lld\n",query(x));
	}
	return 0;
}
