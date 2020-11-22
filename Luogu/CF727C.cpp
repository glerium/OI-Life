#include <cstdio>
using namespace std;
int n,a[10007];
int main(){
	scanf("%d",&n);
	int x1,x2,x3;
	for(int i=1;i<=n-2;i++){
		printf("? %d %d\n",i,i+1); fflush(stdout);
		scanf("%d",&x1);
		printf("? %d %d\n",i,i+2); fflush(stdout);
		scanf("%d",&x3);
		printf("? %d %d\n",i+1,i+2); fflush(stdout);
		scanf("%d",&x2);
		int p=(x1+x2+x3)/2;
		a[i]=p-x2; a[i+1]=p-x3; a[i+2]=p-x1;
	}
	printf("! ");
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	fflush(stdout);
	return 0;
}
