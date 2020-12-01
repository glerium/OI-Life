#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int t,n;
double f[maxn];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		f[n]=0;
		for(int i=n-1;i>=0;i--) f[i]=f[i+1]+1.0*n/(n-i);
		printf("%.2lf\n",f[0]);
	}
	return 0;
}
