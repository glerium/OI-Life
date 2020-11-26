#include <bits/stdc++.h>
using namespace std;
int n,ans;
class Treap{
	int _nxt=23333,root=0;
	int _rand() {return _nxt=1ll*_nxt*19371%998244353;}
public:
	static const int maxn=1e5+10;
	int ct,val[maxn],w[maxn],son[maxn][2],sz[maxn];
	int new_node(int v){
		int id=++ct;
		val[id]=v; w[id]=_rand(); sz[id]=1;
		son[id][0]=son[id][1]=0;
		return id;
	}
	void update(int x){sz[x]=sz[son[x][0]]+sz[son[x][1]]+1;}
	void split(int x,int &a,int &b,int v){
		if(!x) {a=b=0; return;}
		if(val[x]<=v) a=x,split(son[x][1],son[x][1],b,v);
		else b=x,split(son[x][0],a,son[x][0],v);
		update(x);
	}
	void merge(int &x,int a,int b){
		if(!a||!b) {x=a+b; return;}
		if(w[a]<w[b]) x=a,merge(son[x][1],son[x][1],b);
		else x=b,merge(son[x][0],a,son[x][0]);
		update(x);
	}
	void insert(int x){
		int z=new_node(x),a,b;
		split(root,a,b,x); merge(a,a,z); merge(root,a,b);
	}
	int xrank(int x,int v){
		if(v==sz[son[x][0]]+1) return val[x];
		else if(v<=sz[son[x][0]]) return xrank(son[x][0],v);
		else return xrank(son[x][1],v-sz[son[x][0]]-1);
	}
	int pre(int v){
		int x,y; split(root,x,y,v);
		int ans=xrank(x,sz[x]); merge(root,x,y);
		return ans;
	}
	int nxt(int v){
		int x,y; split(root,x,y,v-1);
		int ans=xrank(y,1); merge(root,x,y);
		return ans;
	}
}t;
int main(){
	scanf("%d",&n);
	t.insert(-1e8); t.insert(1e8);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		ans+=i==1?x:min(abs(t.pre(x)-x),abs(t.nxt(x)-x));
//		printf("%d %d\n",t.pre(x),t.nxt(x));
		t.insert(x);
	}
	printf("%d\n",ans);
	return 0;
}
