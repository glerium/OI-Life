#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
const int maxn=1007;
const int MAX=1.1e9;
int n,a[maxn],b[maxn],ans[maxn],cnt;
bool v[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		int minn=MAX,mi;
		for(int j=1;j<=n;j++){
			if(b[j]>a[i]&&b[j]<minn&&!v[j]){
				minn=b[j];
				mi=j;
			}
		}
		if(minn==MAX){
			for(int j=1;j<=n;j++){
				if(!v[j]){
					ans[i]=b[j];
					v[j]=true;
					break;
				}
			}
		}else{
			ans[i]=minn;
			v[mi]=true;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(ans[i]>a[i]&&ans[j]>a[j]&&ans[i]>a[j]&&ans[j]>a[i]&&ans[i]<ans[j]) swap(ans[i],ans[j]);
			else if(((ans[i]>a[i])^(ans[j]>a[j]))&&((ans[i]>a[j])^(ans[j]>a[i]))&&ans[i]<ans[j]) swap(ans[i],ans[j]);
			else if((ans[i]<=a[i]&&ans[j]<=a[j])&&(ans[i]<=a[j]&&ans[j]<=a[i])&&ans[i]<ans[j]) swap(ans[i],ans[j]);
//			for(int i=1;i<=n;i++) printf("%d ",ans[i]);
//			puts("");
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	puts("");
	return 0;
}
