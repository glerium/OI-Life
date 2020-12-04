#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
int n,m,r[maxn],ct,to[maxn],qct;
ll ans=0;
struct Data{
	int id,x;
	bool operator<(const Data& rhs)const{return x<rhs.x;}
}a[maxn];
struct Range{
	int l,r;
	bool operator<(const Range& rhs)const{return l==rhs.l?r<rhs.r:l<rhs.l;}
}t[maxn<<1];
struct Query{
	int id,l,r;
	bool operator<(const Query& rhs)const{return l==rhs.l?r<rhs.r:l<rhs.l;}
}que[maxn];
void add(int l,int r){
	t[++ct]=(Range){min(l,r),max(l,r)};
}
int f[maxn];
int lowbit(int x){
	return x&-x;
}
void tadd(int x,int v){
	while(x<=n){
		f[x]+=v;
		x+=lowbit(x);
	}
}
int query(int x){
	int ans=0;
	while(x){
		ans+=f[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].x),a[i].id=i;
	sort(a+1,a+1+n);
	a[0].x=a[n+1].x=1e8;
	for(int i=1;i<=n;i++){
		int x=abs(a[i].x-a[i-1].x),y=abs(a[i+1].x-a[i].x);
		if(x==y) add(a[i-1].id,a[i].id),add(a[i].id,a[i+1].id);
		else if(x<y) add(a[i-1].id,a[i].id);
		else add(a[i].id,a[i+1].id);
	}
	sort(t+1,t+ct+1);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		que[i]=(Query){i,x,y};
	}
	sort(que+1,que+m+1);
	for(int i=m,j=ct;i>=1;i--){
		while(t[j].l>=que[i].l&&j){
			tadd(t[j].r,1);
			j--;
		}
		ans+=que[i].id*query(que[i].r);
	}
	printf("%lld\n",ans);
	return 0;
}
