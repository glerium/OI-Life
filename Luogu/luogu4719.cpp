#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m,w[maxn],cnt,head[maxn],dep[maxn],sz[maxn],fa[maxn],son[maxn],top[maxn],fuka[maxn];
struct Edge{
	int to,nxt;
}a[maxn<<1];
void dfs1(int x,int from){
	fa[x]=from; dep[x]=dep[from]+1; sz[x]=1;
	
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=n-1;i++){
		read(x),read(y);
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	
}
