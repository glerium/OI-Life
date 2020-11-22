#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e4+10;
int n,m,a[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	int ans1=0,ans2=0;
	for(int i=1;i<=m;i++){
		ans1=max(ans1,min(a[i],n+1-a[i]));
		ans2=max(ans2,max(a[i],n+1-a[i]));
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}
