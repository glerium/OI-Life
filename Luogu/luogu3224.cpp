#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m,rt[maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar();
	x=v*w;return;
}
class Treap{
	int _nxt=23333,root=0;
	int rand(){
		return _nxt=1ll*_nxt*19371%100000007;
	}
public:
	int ct,val[maxn<<2],son[maxn<<2][2],w[maxn<<2],sz[maxn<<2];
	int new_node(int x){
		int id=++ct;
		val[id]=x;
		son[id][0]=son[id][1]=0;
		w[id]=rand();
		return id;
	}
	void update(int x){
		sz[x]=sz[son[x][0]]+sz[son[x][1]]+1;
	}
	void split(int x,int &a,int &b,int v){
		if(!x){
			a=b=0;
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
		if(w[a]<w[b]) x=a,merge(son[a][1],son[a][1],b);
		else x=b,merge(son[a][0],a,son[a][0]);
		update(x);
	}
	void insert(int v){
		int x,y,z;
		split(root,x,y,v);
		z=new_node(v);
		merge(x,x,z);
		merge(root,x,y);
	}
	int xrank(int x,int v){
		if(v==sz[son[x][0]]+1) return val[x];
		if(val[x]<=v) return xrank(son[x][0],v);
		else return xrank(son[x][1],v-sz[son[x][0]]-1);
	}
};
struct ufs{
	int fa[maxn];
	int find(int x){
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		fa[find(x)]=find(y);
	}
};
int main(){
	read(n),read(m);
	for(int i=1,x;i<=n;i++) read(x),rt[i]=new_node(x);
	
}
