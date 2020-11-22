#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <algorithm> 
using namespace std;
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar();
	x=v*w;
}
template<typename T>void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n;
struct Treap{
	const static int maxn=1e5+10;
	int idx,w[maxn],val[maxn],son[maxn][2],sz[maxn],ct[maxn];
	int root=0;
	void update(int x){
		sz[x]=sz[son[x][0]]+sz[son[x][1]]+ct[x];
	}
	void rotate(int &x,int k){
		int y=son[x][k^1];
		son[x][k^1]=son[y][k];
		son[y][k]=x;
		update(x);
		update(y);
		x=y;
	}
	void insert(int &x,int k){
		if(!x){
			x=++idx;
			sz[x]=ct[x]=1;
			val[x]=k;
			w[x]=rand();
		}else if(val[x]==k){
			ct[x]++;
			sz[x]++;
		}else{
			int t=k>val[x];
			insert(son[x][t],k);
			if(w[x]<w[son[x][t]]) rotate(x,t^1);
			update(x);
		}
	}
	void del(int &x,int k){
		if(!x) return;
		if(k<val[x]) del(son[x][0],k);
		else if(k>val[x]) del(son[x][1],k);
		else{	//k==val[x]
			if(!son[x][0]&&!son[x][1]){
				ct[x]--; sz[x]--;
				if(!sz[x]) x=0;
			}else if(son[x][0]&&!son[x][1]){
				rotate(x,1);
				del(son[x][1],k);
			}else if(!son[x][0]&&son[x][1]){
				rotate(x,0);
				del(son[x][0],k);
			}else{
				int t=son[x][0]>son[x][1];
				rotate(x,t);
				del(son[x][t],k);
			}
		}
		update(x);
	}
	int rank(int x,int k){
		if(!x) return 0;
		if(k<val[x]) return rank(son[x][0],k);
		else if(k>val[x]) return sz[son[x][0]]+ct[x]+rank(son[x][1],k);
		else return sz[son[x][0]]+1;
	}
	int xrank(int x,int k){
		if(!x) return 0;
		if(k<=sz[son[x][0]]) return xrank(son[x][0],k);
		else if(k>sz[son[x][0]]+ct[x]) return xrank(son[x][1],k-ct[x]-sz[son[x][0]]);
		else return val[x];
	}
	int pre(int x,int k){
		if(!x) return -1e8;
		if(k<=val[x]) return pre(son[x][0],k);
		else return max(val[x],pre(son[x][1],k));
	}
	int nxt(int x,int k){
		if(!x) return 1e8;
		if(val[x]<=k) return nxt(son[x][1],k);
		else return min(val[x],nxt(son[x][0],k));
	}
}t;
int main(){
	srand(time(0));
	read(n);
	for(int i=1,op,x;i<=n;i++){
		read(op),read(x);
		if(op==1) t.insert(t.root,x);
		else if(op==2) t.del(t.root,x);
		else if(op==3) write(t.rank(t.root,x)),putchar('\n');
		else if(op==4) write(t.xrank(t.root,x)),putchar('\n');
		else if(op==5) write(t.pre(t.root,x)),putchar('\n');
		else write(t.nxt(t.root,x)),putchar('\n');
	}
	return 0;
}
