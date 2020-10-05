#include <cstdio>
using namespace std;
const int maxn=5e5+10;
int n,q,cnt,head[maxn],b[maxn],l[maxn];
struct Edge{
	int to,dis;
}a[maxn];
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1,x;i<=n-1;i++){
		scanf("%d",&x);
		add(x,i+1);
	}
	for(int i=1;i<=n;i++) scanf("%d%d",&b[i],&l[i]);
	
}
