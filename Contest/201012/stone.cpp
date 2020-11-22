#include <cstdio>
using namespace std;
const int maxn=1e6+10;
int n,a[maxn];
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int x=1;x<=n;x++){
		int cnt=0;
		for(int i=1;i<=n;i++) cnt^=a[i]%(x+1);
		printf("%s ",cnt?"Alice":"Bob");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
