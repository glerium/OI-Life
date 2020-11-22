#include <cstdio>
#include <algorithm>
using namespace std;
int sub(int x,int y){
	if(x==0&&y==0) return 0;
	if(y>0) return sub(x-1,y-1);
	return sub(x-1,y)+1;
} 
int add(int x,int y){
	if(x>y) swap(x,y);
	if(x==0&&y==1) return 1;
	return add(x,y-1)+1;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a>b) swap(a,b);
	if(a<0){
		if(b>=0){
			if(b>=-a) printf("%d\n",sub(b,-a));
			else printf("-%d\n",sub(-a,b));
		}
		else printf("-%d\n",add(-a,-b));
	}else printf("%d\n",add(a,b));
	return 0;
}
