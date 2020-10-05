#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
double a[20][20],p[20][20];
void gauss(){
	for(int i=1;i<=n;i++){
		int it=i;
		for(int j=i+1;j<=n;j++){
			if(fabs(a[j][i])>fabs(a[it][i]))
				it=j;
		}
		if(it!=i) for(int j=1;j<=n+1;j++) swap(a[i][j],a[it][j]);
		for(int j=i+1;j<=n;j++){
			double wjh=a[i][i]/a[j][i];
			for(int k=i;k<=n+1;k++) a[j][k]=a[j][k]*wjh-a[i][k];
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=i+1;j<=n+1;j++) a[i][j]/=a[i][i];
		a[i][i]=1; 
		for(int j=i-1;j>=1;j--){
			a[j][n+1]-=a[j][i]*a[i][n+1];
			a[j][i]=0;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n;j++)
			scanf("%lf",&p[i][j]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			a[i][j]=2*p[i][j]-2*p[i+1][j];
		for(int j=1;j<=n;j++){
			a[i][n+1]+=p[i][j]*p[i][j];
			a[i][n+1]-=p[i+1][j]*p[i+1][j];
		}
	}
	gauss();
	for(int i=1;i<=n;i++) printf("%.3lf ",a[i][n+1]);
	puts("");
	return 0;
}
