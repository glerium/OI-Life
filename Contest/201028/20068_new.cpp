#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
bool f[maxn];
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),f[x]=true,k=max(x,k);
	for(int i=k;i>=0;i--){
		for(int j=0;j<=18;j++){
			if(f[i]&&(i&(1<<j)))
				f[i^(1<<j)]=true;
		}
	}
	for(int i=1,x;i<=m;i++){
		scanf("%d",&x);
		puts(f[x]?"yes":"no");
	}
	return 0;
}
