#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int a[12];
	for(int i=1;i<=n;i++) a[i]=i;
	do{
		for(int i=1;i<=n;i++) printf("%d ",a[i]);
		puts("");
	}while(next_permutation(a+1,a+1+n));
	return 0;
}
