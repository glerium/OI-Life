#include <cstdio>
using namespace std;
const int maxn=1e5+10;
int t,n,a[maxn];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int sg=0;
		for(int i=1;i<=n;i++) sg^=a[i];
		if(sg) puts("Yes");
		else puts("No");
	}
	return 0;
}
