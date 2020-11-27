#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,ori[maxn],rt[maxn],ct;
struct Node{
	int l,r,val;
}a[maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)) v=v*10+ch-'0',ch=getchar();
	x=v*w; return;
}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x; if(x>9)write(x/10);
	putchar(x%10+'0'); return;
}
int build(int l,int r){
	int x=++ct;
	if(l==r) {a[x].val=ori[l]; return x;}
	int mid=l+r>>1;
	a[x].l=build(l,mid); a[x].r=build(mid+1,r);
	return x;
}
int clone(int x){		//new node & clone x to des
	a[++ct]=a[x];
	return ct;
}
int query(int x,int l,int r,int k){
	if(l==r) return a[x].val;
	int mid=l+r>>1;
	if(k<=mid) return query(a[x].l,l,mid,k);
	else return query(a[x].r,mid+1,r,k);
}
int update(int x,int l,int r,int k,int v){
	int id=clone(x);
	if(l==r) {a[id].val=v; return id;}
	int mid=l+r>>1;
	if(k<=mid) a[id].l=update(a[id].l,l,mid,k,v);
	else a[id].r=update(a[id].r,mid+1,r,k,v);
	return id;
}
int main(){
	read(n),read(m);
	for(int i=1;i<=n;i++) read(ori[i]);
	rt[0]=build(1,n);
	for(int i=1,v,op,x,y;i<=m;i++){
		read(v),read(op),read(x);
		if(op==1){
			read(y);
			rt[i]=update(rt[v],1,n,x,y);
		}else{
			printf("%d\n",query(rt[v],1,n,x));
			rt[i]=rt[v];
		}
	}
}
