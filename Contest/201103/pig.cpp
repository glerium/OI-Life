#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int p=998244353;
typedef long long ll;
ll a[1005][1005];
int n,m;
ll getans(int x1,int y1,int x2,int y2){
	ll maxx=-1,minn=1e8;
	for(int i=x1;i<=x2;i++){
		for(int j=y1;j<=y2;j++){
			maxx=max(maxx,a[i][j]);
			minn=min(minn,a[i][j]);
		}
	}
	if(maxx-minn==(y2-y1+1)*(x2-x1+1)-1) return (y2-y1+1)*(x2-x1+1);
	return 0;
}
int main(){
	freopen("pig.in","r",stdin);
	freopen("pig.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x=log2(n),y=log2(m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%lld",&a[i][j]),a[i][j]%=p;
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=i;k<=n;k++){
				for(int l=j;l<=m;l++)
					ans=(ans+getans(i,j,k,l))%p;
			}
		}
	}
	printf("%lld\n",ans);
}
