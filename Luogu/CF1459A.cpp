#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int t,n,a[maxn],b[maxn];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%1d",&b[i]);
		int ct=0,ct2=0;
		for(int i=1;i<=n;i++) ct+=a[i]>b[i],ct2+=a[i]<b[i];
		puts(ct>ct2?"RED":ct<ct2?"BLUE":"EQUAL");
	}
	return 0;
}
