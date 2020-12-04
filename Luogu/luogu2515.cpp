#include <bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
int n,m,w[maxn],v[maxn],d[maxn],head[maxn],head2[maxn],cnt,cnt2,w2[maxn],v2[maxn],in[maxn];
int dfn[maxn],low[maxn],f[maxn][maxn],ima,scc_cnt,id[maxn];
bool ins[maxn];
stack<int> st;
struct Edge{
	int from,to,nxt;
}a[maxn],b[maxn];
void add(int x,int y){
	if(!x) return;
	a[++cnt]=(Edge){x,y,head[x]};
	head[x]=cnt;
}
void add2(int x,int y){
	b[++cnt2]=(Edge){x,y,head2[x]};
	head2[x]=cnt2;
}
void tarjan(int x){
	dfn[x]=low[x]=++ima;
	ins[x]=true;
	st.push(x);
	for(int i=head[x];i;i=a[i].nxt){
		if(!dfn[a[i].to]){
			tarjan(a[i].to);
			low[x]=min(low[x],low[a[i].to]);
		}else if(ins[a[i].to]) low[x]=min(low[x],dfn[a[i].to]);
	}
	if(dfn[x]==low[x]){
		scc_cnt++;
		int t;
		do{
			t=st.top(); st.pop();
			ins[t]=false;
			w2[scc_cnt]+=w[t];
			v2[scc_cnt]+=v[t];
			id[t]=scc_cnt;
		}while(t!=x);
	}
}
void dfs(int x){
	for(int i=w2[x];i<=m;i++) f[x][i]=v2[x];
	for(int i=head2[x];i;i=b[i].nxt){
		dfs(b[i].to);
		for(int j=m-w2[x];j>=0;j--){
			for(int k=0;k<=j;k++){
				f[x][j+w2[x]]=max(f[x][j+w2[x]],f[x][j+w2[x]-k]+f[b[i].to][k]);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]),add(d[i],i);
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=cnt;i++)
		if(id[a[i].from]!=id[a[i].to]) add2(id[a[i].from],id[a[i].to]),in[id[a[i].to]]++;
	for(int i=1;i<=scc_cnt;i++) if(!in[i]) add2(0,i);
	dfs(0);
	printf("%d\n",f[0][m]);
	return 0;
}
