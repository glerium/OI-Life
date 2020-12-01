#include <bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int n,a[maxn],f[maxn],ans1;
long double g[maxn],ans2;
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		f[i]=1;
		for(int j=1;j<i;j++){
			if(a[j]>a[i])
				f[i]=max(f[i],f[j]+1);
		}
		ans1=max(ans1,f[i]);
	}
	printf("%lld ",ans1);
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(a[j]>a[i]&&f[j]==f[i]-1) g[i]+=g[j];
			else if(a[j]==a[i]&&f[j]==f[i]) goto end;
		}
		if(f[i]==1) g[i]=1;
end:;
	}
	for(int i=1;i<=n;i++) if(f[i]==ans1) ans2+=g[i];
	printf("%.0Lf\n",ans2+0.1);
	return 0;
}
