#include <bits/stdc++.h>
using namespace std;
int n,a[23],ans;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),ans=gcd(ans,x>=0?x:-x);
	printf("%d\n",ans);
	return 0;
}
