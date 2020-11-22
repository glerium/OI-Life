#include <cstdio>
using namespace std;
const int maxn=5e4+10;
int n,a[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int sg=0;
	for(int i=1;i<=n;i++) sg^=a[i];
	puts(sg?"win":"lose");
	return 0;
}
