#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
const int maxn=107;
int n,head[maxn],cnt,dfn[maxn],low[maxn],ima,id[maxn],scc_cnt,in[maxn],out[maxn];
bool vis[maxn];
struct Edge{
	int from,to,nxt;
}a[maxn*maxn];
stack<int> st;
void add(int x,int y){
	a[++cnt]=(Edge){x,y,head[x]};
	head[x]=cnt;
}
void tarjan(int x){
	dfn[x]=low[x]=++ima;
	vis[x]=true;
	st.push(x);
	for(int i=head[x];i;i=a[i].nxt){
		if(!dfn[a[i].to]){
			tarjan(a[i].to);
			low[x]=min(low[x],low[a[i].to]);
		}else if(vis[a[i].to]) low[x]=min(low[x],dfn[a[i].to]);
	}
	if(dfn[x]==low[x]){
		scc_cnt++;
		int t;
		do{
			t=st.top(); st.pop();
			id[t]=scc_cnt;
		}while(!st.empty()&&t!=x);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		while(~scanf("%d",&x)&&x) add(i,x);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=cnt;i++){
		if(id[a[i].to]!=id[a[i].from]){
			in[id[a[i].to]]++;
			out[id[a[i].from]]++;
		}
	}
	int ans1=0,ans2=0;
	for(int i=1;i<=scc_cnt;i++){
		if(!in[i]) ans1++;
		if(!out[i]) ans2++;
	}
	printf("%d\n%d\n",ans1,max(ans1,ans2));
	return 0;
}
