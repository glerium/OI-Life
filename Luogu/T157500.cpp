#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,a[maxn],sz,cnt[maxn],ans;
struct Query{
	int l,r,id,ans;
	int lq,rq;
	bool operator<(const Query& rhs)const{return lq==rhs.lq?rq<rhs.rq:lq<rhs.lq;}
}q[maxn];
bool cmp(const Query& lhs,const Query& rhs){
	return lhs.id<rhs.id;
}
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar ();
	x=v*w; return;
}
template<typename T>void write(T x){
	if(x<0) putchar ('-'),x=-x;
	if(x>9) write(x/10);
	putchar (x%10+'0');
}
int main(){
	read(n),read(m);
	sz=sqrt(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=m;i++) read(q[i].l),read(q[i].r),q[i].id=i,q[i].lq=q[i].l/sz,q[i].rq=q[i].r/sz;
	sort(q+1,q+1+m);
	int l=1,r=0;
	for(int i=1;i<=m;i++){
		while(l<q[i].l){
			if(a[l]<=n){
				if(cnt[a[l]]==a[l]) ans--;
				cnt[a[l]]--;
				if(cnt[a[l]]==a[l]) ans++;
			}
			l++;
		}
		while(l>q[i].l){
			l--;
			if(a[l]>n) continue;
			if(cnt[a[l]]==a[l]) ans--;
			cnt[a[l]]++;
			if(cnt[a[l]]==a[l]) ans++;
		}
		while(r<q[i].r){
			r++;
			if(a[r]>n) continue;
			if(cnt[a[r]]==a[r]) ans--;
			cnt[a[r]]++;
			if(cnt[a[r]]==a[r]) ans++;
		}
		while(r>q[i].r){
			if(a[r]<=n){
				if(cnt[a[r]]==a[r]) ans--;
				cnt[a[r]]--;
				if(cnt[a[r]]==a[r]) ans++;
			}
			r--;
		}
//		for(int i=1;i<=n;i++) printf("%d,%d: %d %d\n",l,r,a[i],cnt[a[i]]);
		q[i].ans=ans;
	}
	sort(q+1,q+1+m,cmp);
	for(int i=1;i<=m;i++) printf("%d\n",q[i].ans);
	return 0;
}
