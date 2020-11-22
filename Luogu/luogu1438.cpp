#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,m,a[maxn],ct;
struct Node{
	int l,r,ls,rs;
	ll val,tag;
}t[maxn<<2];
void update(int x){
	t[x].val=t[t[x].ls].val+t[t[x].rs].val;
}
int build(int l,int r){
	int id=++ct;
	t[id].l=l,t[id].r=r;
	if(l==r){
		t[id].val=a[l]-a[l-1];
		return id;
	}
	int mid=l+r>>1;
	t[id].ls=build(l,mid);
	t[id].rs=build(mid+1,r);
	update(id);
	return id;
}
void pushdown(int id){
	t[t[id].ls].tag+=t[id].tag,
	t[t[id].rs].tag+=t[id].tag;
	t[t[id].ls].val+=t[id].tag*(t[t[id].ls].r-t[t[id].ls].l+1);
	t[t[id].rs].val+=t[id].tag*(t[t[id].rs].r-t[t[id].rs].l+1);
	t[id].tag=0;
}
void add(int x,int l,int r,ll v){
	if(t[x].tag) pushdown(x);
	if(l<=t[x].l&&t[x].r<=r){
		t[x].val+=v*(t[x].r-t[x].l+1);
		t[x].tag+=v;
		return;
	}
	int mid=t[x].l+t[x].r>>1;
	if(l<=mid) add(t[x].ls,l,r,v);
	if(r>mid) add(t[x].rs,l,r,v);
	update(x);
}
ll query(int x,int l,int r){
	if(t[x].tag) pushdown(x);
	if(l<=t[x].l&&t[x].r<=r) return t[x].val;
	ll ans=0;
	int mid=t[x].l+t[x].r>>1;
	if(l<=mid) ans+=query(t[x].ls,l,r);
	if(r>mid) ans+=query(t[x].rs,l,r);
	return ans;
}
int main(){
//	freopen("test.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,n);
	for(int i=1,op,x,y,k,d;i<=m;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d%d%d",&x,&y,&k,&d);
			add(1,x,x,k);
			if(y>x) add(1,x+1,y,d);
			if(y+1<=n) add(1,y+1,y+1,-1ll*d*(y-x)-k);
		}else if(op==2){
			scanf("%d",&x);
			printf("%lld\n",query(1,1,x));
		}
	}
	return 0;
}
