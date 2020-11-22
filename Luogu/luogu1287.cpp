#include <cstdio>
using namespace std;
int f(int n,int m){
	if(n<0&&m<0) return 0;
	if(n==m) return 1;
	if(m>n) return 0;
	return f(n-1,m-1)+f(n-1,m)*m;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int ans=f(n,m);
	for(int i=1;i<=m;i++) ans*=i;
	printf("%d\n",ans);
	return 0;
}
