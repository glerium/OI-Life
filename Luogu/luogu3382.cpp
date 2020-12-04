#include <bits/stdc++.h>
using namespace std;
const int maxn=15;
int n;
double l,r,a[maxn];
double f(double x){
	double ans=a[1];
	for(int i=2;i<=n+1;i++) ans=ans*x+a[i];
	return ans;
}
int main(){
	scanf("%d%lf%lf",&n,&l,&r);
	for(int i=1;i<=n+1;i++) scanf("%lf",&a[i]);
	while(r-l>1e-7){
		double lmid=(l*2+r)/3,rmid=(l+r*2)/3;
		if(f(lmid)<f(rmid)) l=lmid;
		else r=rmid;
	}
	printf("%.5lf\n",l);
	return 0;
}
