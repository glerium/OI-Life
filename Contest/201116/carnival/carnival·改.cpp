#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2e5+10;
int n,w[maxn],head[maxn],cnt,f[maxn];
struct Edge{
	int to,nxt;
}a[maxn];
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1,x,y;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	
}
