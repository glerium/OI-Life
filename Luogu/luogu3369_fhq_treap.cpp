#include <cstdio>
using namespace std;
int n;
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
	int _nxt=0,root=0;
	int rand(){
		_nxt=(_nxt*23333ll+99999)%1000000007;
		return _nxt;
	}
public:
	static const int maxn=1e6+10;
	int val[maxn],son[maxn][2],idx,sz[maxn],ct[maxn],w[maxn];
	int new_node(int v){
		int x=++idx;
		val[x]=v;
		sz[x]=ct[x]=1;
		son[x][0]=son[x][1]=0;
		w[x]=Treap::rand();
		return x;
	}
	void split(int x,int &a,int &b,int v){
		
	}
	void merge(int &x,int a,int b){
		
	}
	void update(int x){
		
	}
	int gval(int x,int v){
		
	}
	int find(int v){return gval(root,v);}
	void insert(int v){
		
	}
	void erase(int v){
		
	}
	int rank(int v){
		
	}
	int pre(int v){
		
	}
	int suc(int v){
		
	}
}t;
int main(){
	read(n);
	for(int i=1,op,x;i<=n;i++){
		read(op),read(x);
		if(op==1) t.insert(x);
		else if(op==2) t.erase(x);
		else if(op==3) write(t.rank(x)),putchar('\n');
		else if(op==4) write(t.find(x)),putchar('\n');
		else if(op==5) write(t.pre(x)),putchar('\n');
		else write(t.suc(x)),putchar('\n');
	}
	return 0;
}
