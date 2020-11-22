#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,cnt;
ll a[107],k;
bool sel[107];
int main(){
	freopen("lighthouse.in","r",stdin);
	freopen("lighthouse.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n<=10){
		int ans=1e7;
		do{
			ll cur=0;
			int ret=0;
			for(int i=1;i<=n;i++){
				if(cur+a[i]>k){
					cur=0;
					ret++;
				}
				if(ret>=ans) break;
				cur+=a[i];
			}
			ans=min(ans,ret);
		} while(next_permutation(a+1,a+1+n));
		printf("%d\n",ans);
	}else{
		cnt=n;
		int ans=0;
		while(cnt){
			ll maxv=0,maxst;
			for(ll i=0;i<(1<<n);i++){
				ll curv=0;
				bool flag=true;
				for(int j=0;j<n;j++){
					if((1<<j)&i){
						if(sel[j+1]||curv+a[j+1]>k){
							flag=false;
							break;
						} else curv+=a[j+1];
					}
				}
				if(flag){
//					printf("%lld\n",i);
					if(curv>maxv){
						maxst=i;
						maxv=curv;
					}
				}
			}
			for(int i=0;i<n;i++){
				if((1<<i)&maxst){
//					printf("%d ",i+1);
					sel[i+1]=true;
					cnt--;
				}
			}
//			puts("");
			ans++;
		}
		printf("%d\n",ans-1);
	}
	return 0;
}
