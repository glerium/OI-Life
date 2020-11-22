#include <cstdio>
using namespace std;
const int maxn=2e5+10;
int n,q,head[maxn],cnt;
struct Edge{
	int to,nxt;
}a[maxn];
void add(int x,int y){
	a[++cnt](Edge){y,head[x]};
	head[x]=cnt;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1,x,y;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	for(int i=1,a,b,c,d;i<=q;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		
	}
}
