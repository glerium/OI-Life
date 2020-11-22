#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,k;
ll ans;
struct Enemy{
	int id;
	ll atk,def;
	bool operator<(const Enemy& rhs)const{return atk-def<rhs.atk-rhs.def;}
}a[maxn];
int main(){
	freopen("strategy.in","r",stdin);
	freopen("strategy.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].atk,&a[i].def),a[i].id=i;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ans=0;
		int cnt=1;
		int j=1;
		for(j=1;j<=n&&cnt<=k&&a[j].atk<a[i].def;j++){
			if(i==a[j].id) continue;
			cnt++;
			ans+=a[j].atk;
		}
		for(int k=j;k<=n;k++){
			if(i==a[k].id) continue;
			ans+=a[k].def;
		}
		printf("%lld ",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
