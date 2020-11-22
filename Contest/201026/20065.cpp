#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,m,a[maxn],c[maxn][20];
ll s[maxn];
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=10){
		for(int i=1;i<=m;i++){
			int l,r,b[15];
			bool exi[1200]={};
			scanf("%d%d",&l,&r);
			for(int j=l;j<=r;j++) b[j-l]=a[j];
			for(int j=0;j<(1<<(r-l+1));j++){
				int cur=0;
				for(int k=0;k<=r-l;k++){
					if(j&(1<<k))
						cur+=b[k];
				}
				exi[cur]=true;
			}
			for(int i=1;i<=1050;i++) if(!exi[i]){
				printf("%d\n",i);
				break;
			}
		}
	}else{
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=20;j++)
				c[i][j]=c[i-1][j];
			c[i][int(log2(a[i]))]++;
		}
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		for(int i=1;i<=m;i++){
			int l,r;
			scanf("%d%d",&l,&r);
			for(int j=0;j<=20;j++){
				if(c[r][j]-c[l-1][j]==0){
					printf("%lld\n",s[r]-s[l-1]+1);
					break;
				}
			}
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
