#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m,id;
ll a[maxn];
struct Node{
	int l,r,ls,rs;
	ll lval,rval;
	ll v,tag;
}t[maxn<<2];

template<typename T> void read(T& x);
int build(int l,int r);
void update(int x);
void pushdown(int x);
void add(int l,int r,ll v);
ll query(int l,int r);

template<typename T> void read(T& x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-') w=-1; ch=getchar ();}
	while(ch<='9'&&ch>='0'){v=v*10+ch-'0'; ch=getchar ();}
	x=v*w; return;
}

void update(int x){
	int ls=t[x].ls,rs=t[x].rs;
	t[x].lval=t[ls].lval;
	t[x].rval=t[rs].rval;
	t[x].v=t[ls].v+t[rs].v-min(t[ls].rval,t[rs].lval);
}

void pushdown(int x){
	int ls=t[x].ls,rs=t[x].rs;
	t[ls].lval+=t[x].tag; t[ls].rval+=t[x].tag;
	t[rs].lval+=t[x].tag; t[rs].rval+=t[x].tag;
	t[ls].tag+=t[x].tag; t[rs].tag+=t[x].tag;
	t[ls].v+=t[x].tag; t[rs].v+=t[x].tag;
	t[x].tag=0;
	update(x);
}

int build(int l,int r){
	int ret=++id;
	t[ret].l=l,t[ret].r=r;
	if(l==r){
		t[ret].v=a[l];
		t[ret].lval=t[ret].rval=a[l];
		return ret;
	}
	t[ret].ls=build(l,l+r>>1);
	t[ret].rs=build((l+r>>1)+1,r);
	update(ret);
	return ret;
}

void add(int x,int l,int r,ll v){
	if(l<=t[x].l&&t[x].r<=r){
		t[x].lval+=v; t[x].rval+=v;
		t[x].v+=v; t[x].tag+=v;
		return;
	}
	if(t[x].tag) pushdown(x);
	if(l<=(t[x].l+t[x].r>>1)) add(t[x].ls,l,r,v);
	if(r>(t[x].l+t[x].r>>1)) add(t[x].rs,l,r,v);
	update(x);
}

ll query(int x,int l,int r){
	if(l<=t[x].l&&t[x].r<=r)
		return t[x].v;
	if(t[x].tag) pushdown(x);
	int cnt=0;
	ll ans=0;
	if(l<=(t[x].l+t[x].r>>1)) ans+=query(t[x].ls,l,r),cnt++;
	if(r>(t[x].l+t[x].r>>1)) ans+=query(t[x].rs,l,r),cnt++;
	if(cnt==2) ans-=min(t[t[x].ls].rval,t[t[x].rs].lval);
	return ans;
}

int main(){
	read(n),read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	build(1,n);
	for(int i=1,op,l,r,k;i<=m;i++){
		read(op),read(l),read(r);
		if(op==1) read(k),add(1,l,r,k);
		else printf("%lld\n",query(1,l,r));
	}
	return 0;
}
