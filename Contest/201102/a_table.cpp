#include <cstdio>
#include <cmath>
#include <cfloat>
#include <algorithm>
using namespace std;
long long t,n;
int main(){
//	freopen("a_table.out","w",stdout);
	scanf("%lld",&t);
	const long double two=2,one=1;
	long double mm=12,f=sqrt(two);
	const long double ix1=ceil(f)-f,ix2=f-floor(f);
	while(t--){
		scanf("%lld",&n);
		long double f1=0,f2=0;
		for(long long i=1;i<=n;i++){
//			printf("%02d %.7lf %.7lf ",i,ceil(ff)-ff,ff-floor(ff));
			f1+=ix1,f2+=ix2;
			if(f1>=one) f1-=one;
			if(f2>=one) f2-=one;
			if(min(f1,f2)<mm){
				printf("%lld \n",i);
				mm=min(f1,f2);
			}
		}
	}
}
