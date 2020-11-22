#include <cstdio>
#include <algorithm>
using namespace std;
int t;
long long n;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
//		long long ans=0;
//		while(n!=1){
//			long long ori=ans;
//			for(long long i=2;i*i<=n;i++){
//				if(n%i==0){
//					n=i;
//					ans++;
//					break;
//				}
//			}
//			if(ans==ori) n--,ans++;
//		}
//		printf("%lld\n",ans);
		if(n==1) puts("0");
		else if(n==2) puts("1");
		else if(n==3) puts("2");
		else if(n&1) puts("3");
		else puts("2");
	}
	return 0;
}
