#include <cstdio>
using namespace std;
typedef long long ll;
int n,m;
template<typename T>void read(T& x){
	T v=0,w=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar();
	x=v*w;return;
}
template<typename T>void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
struct Treap{
private:
	int _nxt=19371,root=0;
	int rand(){
		_nxt=(_nxt*23333ll+99999)%1000007;
		return _nxt;
	}
public:
	static const int maxn=2e6+10;
	ll val[maxn];
	int son[maxn][2],idx,sz[maxn],w[maxn];
	int new_node(ll v){
		int x=++idx;
		val[x]=v;
		sz[x]=1;
		son[x][0]=son[x][1]=0;
		w[x]=Treap::rand();
		return x;
	}
	void update(int x){
		sz[x]=sz[son[x][0]]+sz[son[x][1]]+1;
	}
	void split(int x,int &a,int &b,ll v){
		if(!x){
			a=0,b=0;
			return;
		}
		if(val[x]<=v) a=x,split(son[x][1],son[x][1],b,v);
		else b=x,split(son[x][0],a,son[x][0],v);
		update(x);
	}
	void merge(int &x,int a,int b){
		if(!a||!b){
			x=a+b;
			return;
		}
		if(w[a]<w[b]) x=a,merge(son[x][1],son[a][1],b);
		else x=b,merge(son[x][0],a,son[b][0]);
		update(x);
	}
	ll xrank(int x,int v){
		if(sz[son[x][0]]+1==v) return val[x];
		if(sz[son[x][0]]>=v) return xrank(son[x][0],v);
		else return xrank(son[x][1],v-sz[son[x][0]]-1);
	}
	ll find(int v){return xrank(root,v);}
	void insert(ll v){
		int in=new_node(v),x,y;
		split(root,x,y,v);
		merge(x,x,in);
		merge(root,x,y);
		update(root);
	}
	void erase(ll v){
		int x,y,z;
		split(root,x,y,v);
		split(x,x,z,v-1);
		merge(z,z[son][0],z[son][1]);
		merge(x,x,z);
		merge(root,x,y);
	}
	int rank(ll v){
		int x,y,ans;
		split(root,x,y,v-1);
		ans=sz[x]+1;
		merge(root,x,y);
		return ans;
	}
	ll pre(ll v){
		int x,y; ll ans;
		split(root,x,y,v-1);
		ans=xrank(x,sz[x]);
		merge(root,x,y);
		return ans;
	}
	ll suc(ll v){
		int x,y; ll ans;
		split(root,x,y,v);
		ans=xrank(y,1);
		merge(root,x,y);
		return ans;
	}
}t;
int main(){
	read(n),read(m);
	for(int i=1,x;i<=n;i++) read(x),t.insert(x);
	int last=0; ll ans=0;
	for(int i=1,op,x;i<=m;i++){
		read(op),read(x); x^=last;
		if(op==1) t.insert(x);
		else if(op==2) t.erase(x);
		else if(op==3) ans^=last=t.rank(x);
		else if(op==4) ans^=last=t.find(x);
		else if(op==5) ans^=last=t.pre(x);
		else ans^=last=t.suc(x);
	}
	write(ans);
	return 0;
}
