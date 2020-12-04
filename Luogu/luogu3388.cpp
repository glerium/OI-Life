#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m,cnt,head[maxn],dfn[maxn],low[maxn],ima;
bool iscut[maxn];
struct Edge{
	int to,nxt;
}a[maxn];
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
void tarjan(int x,int root){
	dfn[x]=low[x]=++ima;
	int son_cnt=0;
	for(int i=head[x];i;i=a[i].nxt){
		if(!dfn[a[i].to]){
			son_cnt++;
			tarjan(a[i].to,root);
			low[x]=min(low[x],low[a[i].to]);
			if(low[a[i].to]>=dfn[x]&&x!=root) iscut[x]=true;
		}else low[x]=min(low[x],dfn[a[i].to]);
	}
	if(x==root&&son_cnt>=2) iscut[x]=true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,i);
	int ans1=0;
	for(int i=1;i<=n;i++) ans1+=iscut[i];
	printf("%d\n",ans1);
	for(int i=1;i<=n;i++) if(iscut[i]) printf("%d ",i);
	return 0;
}
