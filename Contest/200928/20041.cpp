#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k,a[maxn],f[maxn];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(k==0){
		memset(f,0x3f,sizeof(f));
		f[0]=0;
		for(int i=1;i<=n;i++){
			f[i]=min(f[i],f[i-1]+a[i]);
			f[i]=min(f[i],f[i-2]+a[i]);
			if(i>1){
				f[i]=min(f[i],f[i-2]+a[i-1]);
				if(i>2) f[i]=min(f[i],f[i-3]+a[i-1]);
			}
		}
		printf("%d\n",f[n]);
	}
}
