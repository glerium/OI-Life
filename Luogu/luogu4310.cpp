#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn],f[50];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int k=0;
		for(int j=0;j<=30;j++) if(a[i]&(1<<j)) k=max(k,f[j]);
		for(int j=0;j<=30;j++) if(a[i]&(1<<j)) f[j]=max(k+1,f[j]);
	}
	int ans=0;
	for(int i=0;i<=30;i++) ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}
