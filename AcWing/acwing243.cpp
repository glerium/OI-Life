#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,m,a[maxn],cnt;
struct Node{
	int l,r,ls,rs;
	ll sum,tag;
}t[maxn<<2];
void getop(char& x){
	char ch=getchar();
	while(ch!='C'&&ch!='Q') ch=getchar();
	x=ch;
}
void update(int x){
	t[x].sum=t[t[x].ls].sum+t[t[x].rs].sum;
}
int build(int l,int r){
	int x=++cnt;
	t[x].l=l,t[x].r=r;
	if(l==r){
		t[x].sum=a[l];
		return x;
	}
	t[x].ls=build(l,l+r>>1);
	t[x].rs=build((l+r>>1)+1,r);
	update(x);
	return x;
}
void pushdown(int x){
	t[t[x].ls].sum+=t[x].tag*(t[t[x].ls].r-t[t[x].ls].l+1);
	t[t[x].rs].sum+=t[x].tag*(t[t[x].rs].r-t[t[x].rs].l+1);
	t[t[x].ls].tag+=t[x].tag,t[t[x].rs].tag+=t[x].tag;
	t[x].tag=0;
}
void add(int x,int l,int r,ll k){
	if(t[x].tag) pushdown(x);
	if(l<=t[x].l&&t[x].r<=r){
		t[x].sum+=k*(t[x].r-t[x].l+1);
		t[x].tag+=k;
		return;
	}
	int mid=t[x].l+t[x].r>>1;
	if(l<=mid) add(t[x].ls,l,r,k);
	if(r>mid) add(t[x].rs,l,r,k);
	update(x);
}
ll query(int x,int l,int r){
	if(t[x].tag) pushdown(x);
	if(l<=t[x].l&&t[x].r<=r) return t[x].sum;
	int mid=t[x].l+t[x].r>>1;
	ll ans=0;
	if(l<=mid) ans+=query(t[x].ls,l,r);
	if(r>mid) ans+=query(t[x].rs,l,r);
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,n);
	char op; int x,y,k;
	for(int i=1;i<=m;i++){
		getop(op);
		scanf("%d%d",&x,&y);
		if(op=='C'){
			scanf("%d",&k);
			add(1,x,y,k);
		}else printf("%lld\n",query(1,x,y));
	}
	return 0;
}
