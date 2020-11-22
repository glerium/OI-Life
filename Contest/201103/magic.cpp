#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=2e6+10;
const int p=1e9+7;
int n,a[maxn],last[maxn];
long long f[maxn];
vector<int> v;
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	v.push_back(0);
	for(int i=1;i<=n;i++) if(a[i]!=a[i-1]) v.push_back(a[i]);
	n=v.size()-1;
	f[0]=1; last[v[1]]=1;
	for(int i=1;i<=n;i++){
//		printf("%d\n",last[i]);
		if(last[v[i]]) f[i]=(f[i-1]+f[last[v[i]]])%p;
		else f[i]=f[i-1];
		last[v[i]]=i;
	}
	printf("%lld\n",f[n]%p);
	return 0;
}
