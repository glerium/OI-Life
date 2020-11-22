#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n,a[107];
bool f[1007][1007];
double ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int tot=0,fr=0;
	for(int i=1;i<=n;i++) tot+=a[i];
	fr=(tot+1)>>1;
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=fr;j>=0;j--){
			for(int k=j;k>=0;k--){
				if(j>=a[i]) f[j][k]|=f[j-a[i]][k];
				if(k>=a[i]) f[j][k]|=f[j][k-a[i]];
			}
		}
	}
	for(int i=fr;i>=1;i--){
		for(int j=fr;j>=1;j--){
			int k=tot-i-j;
			if(i+j>k&&j+k>i&&k+i>j&&f[i][j]){
				double x=i,y=j,z=k;
				double p=(x+y+z)/2;
				double cc=sqrt(p*(p-x)*(p-y)*(p-z));
				ans=max(cc,ans);
			}
		}
	}
	printf("%d\n",ans>=1e-5?int(ans*100):-1);
	return 0;
}
