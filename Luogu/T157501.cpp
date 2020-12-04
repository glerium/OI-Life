#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,f[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&f[i]);
	puts("simple");
	if(n==1) printf("1\n0 %d\n",f[1]);
	else printf("1\n%d %d\n",f[2],f[1]);
	return 0;
}
