#include <cstdio>
using namespace std;
int main(){
	int ans=50; for(int i=1,x;i<=7;i++) scanf("%d",&x),ans+=x;
	int x,y; scanf("%d%d",&x,&y); ans+=x?5:0;
	puts(ans>=y?"AKIOI":"AFO");
	return 0;
}
