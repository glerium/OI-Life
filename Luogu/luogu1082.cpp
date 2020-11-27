#include <bits/stdc++.h>
using namespace std;
int a,b;
void exgcd(int a,int b,int &x,int &y){
	if(!b){x=1,y=0;return;}
	int tx,ty;
	exgcd(b,a%b,tx,ty);
	x=ty,y=tx-a/b*ty;
}
int main(){
	scanf("%d%d",&a,&b);
	int x,y;
	exgcd(a,b,x,y);
	printf("%d\n",(x+b)%b);
	return 0;
}
