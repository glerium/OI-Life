#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1007;
const int MAX=1.1e9;
int n,a[maxn],b[maxn],ans[maxn],maxans;
bool v[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	if(n<=10){
//		sort(b+1,b+1+n);
		int aa[11]={0,3,10,2,10,9,3,9,8,1,1};
		do{
			bool flag=true;
			for(int i=1;i<=10;i++) if(aa[i]!=b[i]) flag=false;
			int cur=0;
			for(int i=1;i<=n;i++) cur+=bool(a[i]<b[i]);
			if(cur>=maxans){
				for(int j=1;j<=n;j++) ans[j]=b[j];
				maxans=cur;
			}
			
		}while(next_permutation(b+1,b+1+n));
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		puts("");
	}else{
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
				else if(((ans[i]>a[i])^(ans[j]>a[j]))&&((ans[i]>a[j])^(ans[j]>a[i]))&&ans[i]<ans[j]) swap(ans[i],ans[j]),printf("swap: %d %d\n",ans[i],ans[j]);
				else if((ans[i]<=a[i]&&ans[j]<=a[j])&&(ans[i]<=a[j]&&ans[j]<=a[i])&&ans[i]<ans[j]) swap(ans[i],ans[j]);
			}
		}
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}
