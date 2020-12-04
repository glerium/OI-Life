#include <bits/stdc++.h>
using namespace std;
const int maxn=3e6+10;
int n,a[maxn],sk[maxn],ans[maxn],tp;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		while(a[sk[tp]]<a[i]&&tp) ans[sk[tp]]=i,tp--;
		sk[++tp]=i;
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
