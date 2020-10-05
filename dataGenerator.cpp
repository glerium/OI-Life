#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
	freopen("data.in","w",stdout);
	const int t=1,n=100;
	const int range=900,lbound=100;
	srand(time(0));
	for(int i=1;i<=t;i++){
		printf("%d\n",n);
		for(int i=1;i<=n;i++) printf("%d ",rand()%range+lbound);
		puts(""); puts("");
	}
	return 0;
}
