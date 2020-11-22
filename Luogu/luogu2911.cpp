#include <cstdio>
using namespace std;
int s[107];
int main(){
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)for(int j=1;j<=b;j++)for(int k=1;k<=c;k++) s[i+j+k]++;
	int mx=0;
	for(int i=1;i<=a+b+c;i++) {
		if(s[i]>s[mx])
			mx=i;
	}
	printf("%d\n",mx);
	return 0;
}
