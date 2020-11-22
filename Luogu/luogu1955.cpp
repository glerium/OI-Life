#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int t,n,cnt;
ll f[maxn];
map<int,ll> mp;
int query(ll x){return f[x]==x?x:f[x]=query(f[x]);}
void merge(ll x,ll y){f[query(y)]=query(x);}
struct Que{
	ll x,y;
	int p;
	bool operator<(const Que& rhs)const{return p>rhs.p;}
}q[maxn];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) f[i]=i;
		mp.clear();
		cnt=0;
		ll x,y;
		for(int i=1,p;i<=n;i++){
			scanf("%lld%lld%d",&x,&y,&p);
			if(!mp.count(x)){
				mp.insert(make_pair(x,++cnt));
				x=cnt;
			}else x=mp[x];
			if(!mp.count(y)){
				mp.insert(make_pair(y,++cnt));
				y=cnt;
			}else y=mp[y];
			q[i]=(Que){x,y,p};
		}
		sort(q+1,q+1+n);
		int i=1;
		while(q[i].p) merge(q[i].x,q[i].y),i++;
		for(;i<=n;i++){
			int x=q[i].x,y=q[i].y;
			if(query(q[i].x)==query(q[i].y)){
				puts("NO");
				goto end;
			}
		}
		puts("YES");
end:	continue;
	}
	return 0;
}
