#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
	freopen("avl.in","r",stdin);
	freopen("avl.out","w",stdout);
	srand(time(0));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) putchar(rand()&1?'0':'1');
	fclose(stdin);
	fclose(stdout);
	return 0;
}
