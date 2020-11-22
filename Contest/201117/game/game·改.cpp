#include <cstdio>
using namespace std;
const int maxn=2e5+10;
int t,n,a[maxn];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int xorsum=0;
		for(int i=1;i<=n;i++) xorsum^=a[i];
		if(xorsum==0){
			puts("Draw");
			continue;
		}
		for(int i=31;i>=0;i--){
			int zrcnt=0,oncnt=0;
			for(int j=1;j<=n;j++){
				if(a[j]&(1<<i)) oncnt++;
				else zrcnt++;
			}
			if(oncnt%2==0) continue;
			int res=(oncnt%4==1);
			if(zrcnt%2==0) puts(res?"Mitsuha":"Taki");
			else{	//zero_ct&1
				puts("Mitsuha");
			}
			break;
		}
	}
	return 0;
}
