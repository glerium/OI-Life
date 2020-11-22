#include <cstdio>
#include <set>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,c[maxn],head[maxn],cnt;
multiset<int,greater<int> > st;
struct Edge{
	int to,nxt;
}a[maxn];
template<typename T>void read(T& x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
ll dfs(int x,int fa){
	ll ans=0;
	multiset<int>::iterator avai=st.upper_bound(c[x]);
//	for(multiset<int>::iterator i=st.begin();i!=st.end();i++) printf("%d ",*i);
//	puts("");
//	ans=distance(avai,st.end());
	if(avai!=st.end()) ans++;
//	printf("%d %d: %lld\n",x,fa,ans);
	multiset<int>::iterator it;
	if(fa) it=st.insert(c[x]);
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==fa) continue;
		ans+=dfs(a[i].to,x);
	}
	if(fa) st.erase(it);
	return ans;
}
int main(){
	freopen("carnival.in","r",stdin);
	freopen("carnival.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(c[i]);
	for(int i=1,x,y;i<=n-1;i++){
		read(x),read(y);
		add(x,y),add(y,x);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		st.clear();
		ans+=dfs(i,0);
	}
	printf("%lld\n",ans-n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
