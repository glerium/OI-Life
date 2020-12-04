#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m,w[maxn],head[maxn],head2[maxn],cnt,cnt2,w2[maxn];
int low[maxn],dfn[maxn],ima,in[maxn],id[maxn],scc_cnt,od[maxn],od_ct,f[maxn];
bool vis[maxn];
stack<int> st;
struct Edge{
	int from,to,nxt;
}a[maxn],b[maxn];
void add(int x,int y){
	a[++cnt]=(Edge){x,y,head[x]};
	head[x]=cnt;
}
void add2(int x,int y){
	b[++cnt2]=(Edge){0,y,head2[x]};
	head2[x]=cnt2;
}
void tarjan(int x){
	st.push(x);
	low[x]=dfn[x]=++ima;
	vis[x]=true;
	for(int i=head[x];i;i=a[i].nxt){
		if(!dfn[a[i].to]) tarjan(a[i].to),low[x]=min(low[x],low[a[i].to]);
		else if(vis[a[i].to]) low[x]=min(low[x],dfn[a[i].to]);
	}
	if(dfn[x]==low[x]){
		scc_cnt++;
		while(1){
			int t=st.top(); st.pop();
			vis[t]=false;
			id[t]=scc_cnt;
			w2[scc_cnt]+=w[t];
			if(dfn[t]==low[t]) break;
		}
	}
}
void topo(){
	queue<int> q;
	for(int i=1;i<=scc_cnt;i++) if(!in[i]) q.push(i);
	while(!q.empty()){
		int x=q.front(); q.pop();
		od[++od_ct]=x;
		for(int i=head2[x];i;i=b[i].nxt) if(!--in[b[i].to]) q.push(b[i].to);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=cnt;i++){
		printf("::%d %d\n",id[a[i].from],id[a[i].to]);
		if(id[a[i].from]!=id[a[i].to]){
			in[id[a[i].to]]++;
			add2(id[a[i].from],id[a[i].to]);
		}
	}
	topo();
	int ans=0;
	for(int i=od_ct;i>=1;i--){
		printf("%d\n",w2[i]);
		f[i]=w2[i];
		for(int j=head2[i];j;j=b[j].nxt) f[i]=max(f[i],f[b[j].to]+w2[i]),printf("::%d\n",f[b[j].to]);
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}
