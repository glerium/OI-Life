#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m,a[maxn],rt[maxn],ori[maxn],v[maxn],c,ct;
map<int,int> mp;
struct Node{
	int l,r;
	int val;
}t[maxn<<4];
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
	if(l==r) {t[x].val=ori[l]; return x;}
	int mid=l+r>>1;
	t[x].l=build(l,mid); t[x].r=build(mid+1,r);
	return x;
}
void update(int x,int l,int r,)
int main(){
	read(n),read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(!mp.count(a[i])){
			v[++c]=a[i];
			mp.insert(make_pair(a[i],c));
		}
		ori[mp[a[i]]]++;
	}
	rt[1]=build(1,c);
	for(int i=2;i<=m;i++){
		t[++ct]=t[rt[i-1]];
		
	}
	for(int i=1,l,r,k;i<=m;i++){
		read(l),read(r),read(k);
		
	}
}
