#include <cstdio>
using namespace std;
int main(){
	int n,k; scanf("%d%d",&n,&k);
	puts(n%(k+1)?"1":"2");
	return 0;
} 
