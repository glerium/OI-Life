#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e4+10;
int n,m,fa[maxn],rk[maxn];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(rk[x]>rk[y]) fa[y]=x,rk[x]=max(rk[x],rk[y]+1);
	else fa[x]=y,rk[y]=max(rk[y],rk[x]+1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,op,x,y;i<=m;i++){
		scanf("%d%d%d",&op,&x,&y);
		if(op==1) merge(x,y);
		else putchar(find(x)==find(y)?'Y':'N'),putchar('\n');
	}
	return 0;
}
