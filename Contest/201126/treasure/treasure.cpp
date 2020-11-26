#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
int n,q;
ll t,out[maxn];
struct Treasure{
	ll w,t;
	bool operator<(const Treasure& rhs)const{return w<rhs.w;}
}a[maxn],ori[maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch>='0'&&ch<='9')v=v*10+ch-'0',ch=getchar ();
	x=v*w; return;
}
bool cmp(const Treasure& rhs,const Treasure& lhs){
	return rhs.t<lhs.t;
}
bool check(int x,int k){
	memcpy(a,ori,sizeof(Treasure)*(n+10));
	sort(a+1,a+x,cmp);
	sort(a+x+1,a+n+1,cmp);
	ll cur=a[x].t;
	int ct1=0,ct2=0;
	int i=1,j=1;
	bool flag1=false,flag2=false;
	for(i=1;i<x&&ct1<k/2;i++){
		if(cur+a[i].t<=t){
			cur+=a[i].t;
			ct1++;
		}else{
			return 0;
		}
		if(ct1==k/2) break;
	}
	for(j=x+1;j<=n&&ct2<k/2;j++){
		if(cur+a[j].t<=t){
			cur+=a[j].t;
			ct2++;
		}else{
			return 0;
		}
		if(ct2==k/2) break;
	}
	return ct1==k/2&&ct2==k/2;
}
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	read(n),read(t),read(q);
	for(int i=1;i<=n;i++) read(a[i].w),read(a[i].t),ori[i]=a[i];
	sort(ori+1,ori+n+1);
	if(q==1){
		int x;
		read(x);
		bool found=false;
		for(int i=n;i>=1;i--){
			if(check(i,x)){
				found=true;
				printf("%lld\n",a[i].w);
				break;
			}
		}
		if(!found) puts("-1");
	}else if(n<=2000){
		for(int i=1,x;i<=n;i++){
			x=i;
			bool found=false;
			int l=1,r=n,mid,ans;
			while(l<=r){
				mid=l+r>>1;
				if(check(mid,x)){
					ans=mid;
					l=mid+1;
					found=true;
				}else r=mid-1;
			}
			if(!found) out[x]=-1;
			else out[x]=ori[ans].w;
		}
		for(int i=1,x;i<=q;i++){
			read(x);
			printf("%lld\n",out[x]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
