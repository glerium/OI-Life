#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=15;
int n;
double pt[maxn][maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n;j++)
			scanf("%lf",&pt[i][j]);
	}
	
	return 0;
}
