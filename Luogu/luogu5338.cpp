#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
unsigned T,n,m,seed,last;
unsigned input(){
	seed=seed*17+last;
	return seed%m+1;
}
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar();
	x=v*w;return;
}
template<typename T>void write(T x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
struct pii{
	int x,y;
	bool operator<(const pii& rhs)const{return x==rhs.x?y>rhs.y:x<rhs.x;}
	bool operator==(const pii& rhs)const{return x==rhs.x&&y==rhs.y;}
	bool operator<=(const pii& rhs)const{return *this<rhs||*this==rhs;}
}a[maxn];
struct Treap{
	int root=0,ct=0,son[maxn<<1][2],w[maxn<<1],sz[maxn<<1];
	pii val[maxn<<1];
	int new_node(pii v){
		int x=++ct;
		val[x]=v;
		w[x]=rand();
		sz[x]=1;
		son[x][0]=son[x][1]=0;
		return x;
	}
	void update(int x){
		sz[x]=sz[son[x][0]]+sz[son[x][1]]+1;
	}
	void split(int x,int &a,int &b,pii v){
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
		if(w[a]<w[b]) x=a,merge(son[x][1],son[x][1],b);
		else x=b,merge(son[x][0],a,son[x][0]);
		update(x);
	}
	void insert(pii v){
		int x,y;
		split(root,x,y,v);
		merge(x,x,new_node(v));
		merge(root,x,y);
	}
	void erase(pii v){
		int x,y,z;
		split(root,x,y,v);
		split(x,x,z,(pii){v.x,v.y+1});
		merge(z,son[z][0],son[z][1]);
		merge(x,x,z);
		merge(root,x,y);
	}
	int rank(pii v){
		int x,y;
		split(root,x,y,v);
		int ans=sz[y];
		merge(root,x,y);
		return ans;
	}
}t;
int main(){
//	int r[4]={7,77,777,7777};
//	printf("%d\n",*(~~1%1+&1[r+1]));
	srand(time(0));
	read(T);
	while(T--){
		memset(&t,0,sizeof(t));
		scanf("%d%d%d",&m,&n,&seed);
		for(unsigned i=1;i<=m;i++) a[i].x=0,a[i].y=1e9,t.insert(a[i]);
		for(unsigned i=1,ria,rib;i<=n;i++){
			ria=input(),rib=input();
			t.erase(a[ria]);
			a[ria].x++,a[ria].y+=rib;
			t.insert(a[ria]);
			printf("%d\n",t.rank(a[ria]));
		}
	}
	return 0;
}
