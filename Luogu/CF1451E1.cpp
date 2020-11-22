#include <cstdio>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn];
int main(){
	scanf("%d",&n);
	{
		int a12,a23,a13,x12,x23,x13;
		printf("AND 1 2\n");
		fflush(stdout);
		scanf("%d",&a12);
		printf("AND 2 3\n");
		fflush(stdout);
		scanf("%d",&a23);
		printf("AND 1 3\n");
		fflush(stdout);
		scanf("%d",&a13);
		printf("XOR 1 2\n");
		fflush(stdout);
		scanf("%d",&x12);
		printf("XOR 2 3\n");
		fflush(stdout);
		scanf("%d",&x23);
		x13=x12^x23;
		int ab=x12+a12*2,
			ac=x13+a13*2,
			bc=x23+a23*2;
		a[1]=(ab+ac-bc)/2;
		a[2]=(ab+bc-ac)/2;
		a[3]=(ac+bc-ab)/2;
	}
	for(int i=4,x;i<=n;i++){
		printf("XOR 1 %d\n",i);
		fflush(stdout);
		scanf("%d",&x);
		a[i]=a[1]^x;
	}
	printf("! ");
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	fflush(stdout);
	return 0;
}
