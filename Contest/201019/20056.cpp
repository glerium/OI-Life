#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=32;
const int p=1e9+7;
int n,k,a[maxn],se[maxn],ans;
void dfs(int x,int d){
//	if(n-x+d<k) return;
	if(d==k){
		ll cur=0;
		int ta[maxn];
		memcpy(ta,a,sizeof(a));
		for(int i=1;i<=k;i++) ta[se[i]]=0;
		for(int i=1;i<=n;i++) cur+=max(0,min(ta[i-1]-ta[i],ta[i+1]-ta[i]));
		if(cur%2==0) ans++;
	}
	for(int i=x+1;i<=n;i++){
		se[d+1]=i;
		dfs(i,d+1);
	}
}
int main(){
	freopen("rain.in","r",stdin);
	freopen("rain.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=a[n+1]=1e9+10;
	dfs(0,0);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
