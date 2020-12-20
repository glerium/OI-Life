#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; scanf("%d",&n);
	if(n%2==0) printf("%d\n",(n/2+1)*(n/2+1));
	else printf("%d\n",(n*n+4*n+3)/2);
	return 0;
}
