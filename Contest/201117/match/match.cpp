#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,a[maxn],b[maxn];
stack<int> q;
int main(){
//	freopen("match.in","r",stdin);
//	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	ll maxs=(1<<n),ans=0;
	for(ll i=0;i<maxs;i++){
		int ct=0;
		for(int j=0;j<n;j++) ct+=bool(i&(1<<j));
//		printf("%lld:: %d\n",i,ct);
		if(ct&1) continue;
		while(!q.empty()) q.pop();
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				if(!q.empty()&&q.top()==1) q.pop();
				else q.push(1);
			}else{
				if(!q.empty()&&q.top()==0) q.pop();
				else q.push(0);
			}
		}
//		printf("%lld\n",i);
		if(!q.empty()) continue;
		ll cur=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)) cur+=a[j+1];
			else cur+=b[j+1];
		}
//		printf("%lld: %lld\n",i,cur);
		ans=max(ans,cur);
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
