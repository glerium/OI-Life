#include <bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int n,k,a[maxn],q[maxn],f,r;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		while(f<=r&&a[q[r]]>=a[i]) r--;
		q[++r]=i;
		while(f<=r&&i-k>=q[f]) f++;
		if(i-k>=0) printf("%d ",a[q[f]]);
	}
	putchar('\n');
	f=r=0;
	memset(q,0,sizeof(q));
	for(int i=1;i<=n;i++){
		while(f<=r&&a[q[r]]<=a[i]) r--;
		q[++r]=i;
		while(f<=r&&i-k>=q[f]) f++;
		if(i-k>=0) printf("%d ",a[q[f]]);
	}
	putchar('\n');
	return 0;
}
