#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define int long long
using namespace std;
const int maxn=1e6+10;
int t,n,p,q,a[maxn],b[maxn],f[maxn][20];
template<typename T> void read(T& x){
	T v=0,w=1; char ch=getchar ();
	while(ch<'0'||ch>'9'){if(ch=='-') w=-1; ch=getchar ();}
	while(ch<='9'&&ch>='0'){v=v*10+ch-'0'; ch=getchar ();}
	x=v*w; return;
}
signed main(){
//	freopen("20044.in","r",stdin);
//	freopen("20044.out","w",stdout);
//	FILE* ansout=fopen("20044.ans","w");
	read(t);
	while(t--){
		int x=0,x2=0,l,r,l2,r2;
		read(n),read(p),read(q);
		for(int i=0;i<n;i++) read(a[i]);
		for(int i=0;i<q/64+2;i++) read(b[i]);
		for(int i=0;i<n;i++) f[i][0]=a[i]%p;
		for(int i=1;i<=log2(n);i++){
			for(int jl=0,jr=jl+pow(2,i)-1;jl<n&&jr<n;jl++,jr++)
				f[jl][i]=1ll*f[jl][i-1]*f[(jl+jr)/2+1][i-1]%p;
		}
		
		for(int i=0;i<q;i++){
			if(i%64==0) l=(b[i/64]+x)%n,r=(b[i/64+1]+x)%n;
			else l=(l+x)%n,r=(r+x)%n;
			if(l>r) swap(l,r);
			int ans=1,ml=l,mr=r;
			while(ml<=mr){
				int kkk=log2(mr-ml+1);
				ans=1ll*ans*f[ml][kkk]%p;
				ml+=pow(2,kkk);
				//if(ml==mr) break;		//这句不能加!!! 
			}
			x=ans+1;
		}
		printf("%d\n",x%p);
	}
	return 0;
}
