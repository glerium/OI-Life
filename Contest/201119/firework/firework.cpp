#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=3e5+10;
typedef long long ll;
int n,m,w;
ll finans=-1e18,a[maxn];
template<typename T>void read(T& x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
ll getans(){
	ll ans=-1e17,cur=0;
	bool found=false;
	for(int i=1;i<=n;i++){
		if(cur+a[i]<0) cur=0;
		else cur+=a[i],found=true;
		ans=max(ans,cur);
	}
	if(found) return ans;
	else{
		ll maxx=-1e17;
		for(int i=1;i<=n;i++) maxx=max(maxx,1ll*a[i]);
		return maxx;
	}
}
void make(int a1,int b1,int a2,int b2,int a3,int b3){
	if(m>=1) for(int i=a1;i<=b1;i++) a[i]*=w;
	if(m>=2) for(int i=a2;i<=b2;i++) a[i]*=w;
	if(m>=3) for(int i=a3;i<=b3;i++) a[i]*=w;
	finans=max(finans,getans());
	if(m>=1) for(int i=a1;i<=b1;i++) a[i]/=w;
	if(m>=2) for(int i=a2;i<=b2;i++) a[i]/=w;
	if(m>=3) for(int i=a3;i<=b3;i++) a[i]/=w;
}
int main(){
	freopen("firework.in","r",stdin);
	freopen("firework.out","w",stdout);
	read(n),read(m),read(w);
	for(int i=1;i<=n;i++) read(a[i]);
	if(m==0||w==1){
		ll ans=-1e17,cur=0;
		bool found=false;
		for(int i=1;i<=n;i++){
			if(cur+a[i]<0) cur=0;
			else cur+=a[i],found=true;
			ans=max(ans,cur);
		}
		if(found) printf("%lld\n",ans);
		else{
			ll maxx=-1e17;
			for(int i=1;i<=n;i++) maxx=max(maxx,1ll*a[i]);
			printf("%lld\n",maxx);
		}
	}else if(n<=12&&m<=3){
		if(m==1){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++)
					make(i,j,0,0,0,0);
			}
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int l=k;l<=n;l++)
							make(i,j,k,l,0,0);
					}
				}
			}
		}else if(m==3){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int l=k;l<=n;l++){
							for(int x=l+1;x<=n;x++){
								for(int y=x;y<=n;y++)
									make(i,j,k,l,x,y);
							}
						}
					}
				}
			}
		}
		printf("%lld\n",finans);
	}else{
		puts("qaq");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
