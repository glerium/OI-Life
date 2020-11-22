#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,t[10],a[10],pre[10];
bool check(){
	for(int i=1;i<n;i++) if(t[i]!=a[i]) return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&t[i]);
	for(int i=1;i<=n;i++) a[i]=i;
	bool first=true;
	do{
		if(check()){
			if(!first) for(int i=1;i<=n;i++) printf("%d ",pre[i]);
			else puts("ERROR");
		}
		first=false;
		memcpy(pre,a,sizeof(a));
	}while(next_permutation(a+1,a+1+n));
	return 0;
} 
