#include <cstdio>
#include <cstring>
#include <stack>
#include <set>
using namespace std;
const int maxn=2e6+10;
int n,m,cnt,head[maxn],vis[maxn],isans[maxn],ffrom,fto,ffound;
bool found=false,found2=false;
struct Edge{
	int id,to,nxt;
}a[maxn];
stack<int> st;
set<int> mp;
template<typename T>void read(T& x){
	int v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch<='9'&&ch>='0'){v=v*10+ch-'0';ch=getchar ();}
	x=v*w; return;
}
void add(int id,int x,int y){
	a[++cnt]=(Edge){id,y,head[x]};
	head[x]=cnt;
}
void dfs(int x,int fa){
//	printf("%d %d %d %d\n",x,fa,found,found2);
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		if(!mp.count(a[i].id)) st.push(a[i].id),mp.insert(a[i].id);
		if(vis[a[i].to]){
			if(found&&a[i].id!=ffound) found2=true;
			else{
				found=true,ffrom=x,fto=a[i].to,ffound=a[i].id;
				if(!mp.count(a[i].id)) st.push(a[i].id),mp.insert(a[i].id);
			}
//			printf("blocked: %d %d\n",x,a[i].to);
		}else{
			vis[a[i].to]=true;
			dfs(a[i].to,x);
		}
	}
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	read(n),read(m);
	for(int i=1,x,y;i<=m;i++) read(x),read(y),add(i,x,y),add(i,y,x);
	for(int i=1;i<=n;i++){
//		for(int i=1;i<=n;i++) printf("%d",vis[i]);
//		puts("");
//		memset(vis,0,sizeof(vis));
		if(vis[i]) continue;
		vis[i]=true;
		found=found2=false;
		while(!st.empty()) st.pop();
		mp.clear();
		
		dfs(i,i);
//		printf("%d %d\n",found,found2);
		if(found&&!found2){
//			int fff=st.top();
//			st.pop(); while(a[fff*2].id==a[st.top()*2].id) fff=st.top(),st.pop();
//			printf("found at: %d %d\n",ffrom,fto);
			int cur=0;
//			while(!st.empty()) printf("::%d %d %d\n",st.top(),a[st.top()*2].to,a[st.top()*2-1].to),st.pop();
			while(!st.empty()&&a[(cur=st.top())*2].to!=fto&&a[cur*2-1].to!=fto) st.pop();
			if(!st.empty()&&cur==st.top()) st.pop();
			isans[cur]=true;
//			printf("cur = %d\n",cur);
			while(!st.empty()&&a[(cur=st.top())*2].to!=ffrom&&a[cur*2-1].to!=ffrom) isans[cur]=true,st.pop();
			isans[cur]=true;
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++) if(isans[i]) ans^=i;
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
