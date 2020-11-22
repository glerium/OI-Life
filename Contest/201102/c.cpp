#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int m;
ll l[maxn],r[maxn],w[maxn];
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&l[i],&r[i],&w[i]);
	int maxk=(1<<m);
	ll ans=-1;
	for(int i=0;i<maxk;i++){
		int used[11]={};
		ll ima=0;
		bool flag=true;
		for(int j=1;j<=m;j++){
			if(i&(1<<(j-1))){
				ima+=w[j];
				for(int k=l[j];k<=r[j];k++){
					used[k]++;
					if(used[k]>2){
						flag=false;
						break;
					}
				}
			}
			if(!flag) break;
		}
		if(flag) ans=max(ans,ima);
	}
	printf("%lld\n",ans);
	return 0;
}
