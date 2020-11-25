#include <cstdio>
#include <cctype>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;
const int maxn=1e6+10;
int n,m,cnt,w[maxn],head[maxn],sz[maxn];
multiset<int> st;
multiset<int,greater<int> >st2;
template<typename T>void read(T& x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
struct Edge{
	int to,nxt;
}a[maxn];
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
void dfs(int x,int fa){
	multiset<int>::iterator it=st.insert(w[x]);
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		dfs(a[i].to,x);
	}
	sz[x]=distance(st.upper_bound(w[x]),st.end());
	st.erase(it);
}
int main(){
	freopen("tears.in","r",stdin);
	freopen("tears.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++) read(w[i]);
	bool is3=true;
	for(int i=1,x,y;i<=n-1;i++){
		read(x),read(y);
		is3&=(x==1&&y==i+1||x==i+1&&y==1);
		add(x,y),add(y,x);
	}
	if(n<=2000&&m<=2000){
		for(int i=1,q;i<=m;i++){
			read(q);
			dfs(q,0);
			long long ans=0;
			for(int j=1;j<=n;j++) ans+=sz[j];
			printf("%lld\n",ans);
		}
	}else if(is3){	//(1,i+1)
		int tmp=0;
		for(int i=2;i<=m;i++) tmp+=(w[i]<w[1]);
		for(int i=2;i<=m;i++) st2.insert(w[i]);
		for(int i=1,q;i<=m;i++){
			read(q);
			if(q==1){
				printf("%d\n",tmp);
				continue;
			}
			long long ans=0;
			ans+=tmp-(w[q]<w[1]);
			ans+=distance(st2.upper_bound(w[q]),st2.end());
			ans+=(w[1]<w[q]);
			printf("%lld\n",ans);
		}
	}else if(m==1){
		int q;
		read(q);
		dfs(q,0);
		long long ans=0;
		for(int j=1;j<=n;j++) ans+=sz[j];
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
