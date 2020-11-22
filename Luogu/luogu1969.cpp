#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans=0;
	for(int i=1;i<=n;i++) ans+=max(0,a[i]-a[i-1]);
	printf("%d\n",ans);
	return 0;
}
