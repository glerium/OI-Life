#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=1e5+10;
int n,m,cnt;
double a[maxn];
int ccc=0;
struct Node{
	int l,r,ls,rs;
	double s,s2,tag;
}t[maxn<<2];
void pushdown(int x){
	int ls=t[x].ls,rs=t[x].rs;
	double &tag=t[x].tag;
	t[ls].s2+=2*tag*t[ls].s+(t[ls].r-t[ls].l+1)*tag*tag;
	t[rs].s2+=2*tag*t[rs].s+(t[rs].r-t[rs].l+1)*tag*tag;
	t[ls].s+=tag*(t[ls].r-t[ls].l+1);
	t[rs].s+=tag*(t[rs].r-t[rs].l+1);
	t[ls].tag+=tag,t[rs].tag+=tag;
	tag=0;
}
void update(int x){
	t[x].s=t[t[x].ls].s+t[t[x].rs].s;
	t[x].s2=t[t[x].ls].s2+t[t[x].rs].s2;
}
int build(int l,int r){
	int rt=++cnt;
	t[rt].l=l,t[rt].r=r;
	if(l==r){
		t[rt].s=a[l];
		t[rt].s2=a[l]*a[l];
		return rt;
	}
	t[rt].ls=build(l,l+r>>1);
	t[rt].rs=build((l+r>>1)+1,r);
	update(rt);
	return rt;
}
void add(int x,int l,int r,double k){
	if(t[x].tag) pushdown(x);
	if(l<=t[x].l&&t[x].r<=r){
		t[x].s2+=2*k*t[x].s+(t[x].r-t[x].l+1)*k*k;
		t[x].s+=(t[x].r-t[x].l+1)*k;
		t[x].tag+=k;
		return;
	}
	int mid=t[x].l+t[x].r>>1;
	if(l<=mid) add(t[x].ls,l,r,k);
	if(r>mid) add(t[x].rs,l,r,k);
	update(x);
}
double query(int x,int l,int r){
	if(t[x].tag) pushdown(x);
	if(l<=t[x].l&&t[x].r<=r) return t[x].s;
	double ans=0;
	int mid=t[x].l+t[x].r>>1;
	if(l<=mid) ans+=query(t[x].ls,l,r);
	if(r>mid) ans+=query(t[x].rs,l,r);
	return ans;
}
double query2(int x,int l,int r){
	if(t[x].tag) pushdown(x);
	if(l<=t[x].l&&t[x].r<=r) return t[x].s2;
	int mid=t[x].l+t[x].r>>1;
	double ans=0;
	if(l<=mid) ans+=query2(t[x].ls,l,r);
	if(r>mid) ans+=query2(t[x].rs,l,r);
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
	build(1,n);
	double k;
	for(int i=1,op,x,y;i<=m;i++){
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){		//添加
			scanf("%lf",&k);
			add(1,x,y,k);
		}else if(op==2){//查询平均值
			double ans=query(1,x,y);
			printf("%.4lf\n",1.0*ans/(y-x+1));
		}else{			//查询方差
			double mean=query(1,x,y)*1.0/(y-x+1),
				   sum2=query2(1,x,y);
			printf("%.4lf\n",sum2/(y-x+1)-mean*mean);
		}
	}
	return 0;
}
