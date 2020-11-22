#include <cstdio>
using namespace std;
const int maxn=1e5+10;
const int p=998244353;
int n,q,a[maxn],p2[maxn];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	p2[0]=1;
	for(int i=1;i<=n;i++) p2[i]=p2[i-1]*2%p;
	scanf("%d",&q);
	int last=0;
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		l^=last,r^=last;
		printf("%d\n",p2[r-l+1]);
		last=p2[r-l+1];
	}
	return 0;
}
