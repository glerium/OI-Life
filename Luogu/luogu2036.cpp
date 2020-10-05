#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
struct Food{
	int s,b;
}a[20];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].s>>a[i].b;
	int maxs=(1<<n),ans=1e9;
	for(int i=1;i<maxs;i++){
		int aa=1,bb=0;
		for(int j=0;j<n;j++) if((i>>j)&1) aa*=a[j+1].s,bb+=a[j+1].b;
		ans=min(ans,abs(aa-bb));
	}
	printf("%d\n",ans);
	return 0;
}
