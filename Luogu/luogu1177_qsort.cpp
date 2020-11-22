#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn];
void qsort(int l,int r){
	if(l>=r) return;
	int k=l,i=l,j=r;
	while(i<j){
		while(i<j&&a[i]<k) i++;
		if(i<j){
			swap(a[i],a[k]);
			k=i;
		}
		while(i<j&&a[j]>k) j--;
		if(i<j){
			swap(a[j],a[k]);
			k=j;
		}
	}
	printf("%d: ",a[k]);
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	puts("");
	qsort(l,k-1);
	qsort(k+1,r);
}
int main(){
//	freopen("P1177_1.in","r",stdin);
//	freopen("P1177_1.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	qsort(1,n);
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	puts("");
	return 0;
}
