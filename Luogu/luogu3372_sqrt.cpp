#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m,sz,id[maxn];
ll tag[maxn],a[maxn],s[maxn];
void add(int x,int y,ll k){
	int l=x/sz+bool(x%sz),r=y/sz+bool(y%sz);	//x:floor, y:ceil
//	printf(":%d %d %d %d\n",x,y,l,r);
	if((x-1)%sz!=0){
		for(int i=x;i<=l*sz;i++) a[i]+=k,s[i/sz+bool(i%sz)]+=k;	//left
		l++;
	}
	if(r*sz>y){
		for(int i=(r-1)*sz+1;i<=y;i++) a[i]+=k,s[i/sz+bool(i%sz)]+=k;	//right
		r--;
	}
//	printf("::%d %d %d %d\n",x,y,l,r);
	for(int i=l;i<=r;i++) tag[i]+=k,s[i]+=k*sz;		//mid
}
ll query(int x,int y){
	ll ans=0;
	int l=x/sz+bool(x%sz),r=y/sz+bool(y%sz);	//x:floor, y:ceil
//	printf(":%d %d %d %d\n",x,y,l,r);
	if((x-1)%sz!=0){
		for(int i=x;i<=l*sz;i++) ans+=a[i]+tag[i/sz+bool(i%sz)];	//left
		l++;
	}
	if(r*sz>y){
		for(int i=(r-1)*sz+1;i<=y;i++) ans+=a[i]+tag[i/sz+bool(i%sz)];	//right
		r--;
	}
//	printf("::%d %d %d %d->%d\n",x,y,l,r,ans);
	for(int i=l;i<=r;i++) ans+=s[i];		//mid
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	sz=sqrt(n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) s[i/sz+bool(i%sz)]+=a[i];
	ll k;
	for(int i=1,op,x,y;i<=m;i++){
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			scanf("%lld",&k);
			add(x,y,k);
		}else printf("%lld\n",query(x,y));
	}
	return 0;
}
