#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m,q,rt[maxn],toid[maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar();
	x=v*w;return;
}
template<typename T>void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
char nxt_op(){
	char ch=getchar();
	while(ch!='Q'&&ch!='B') ch=getchar();
	return ch;
}
int _nxt=23333;
int _rand(){
	return _nxt=1ll*_nxt*19371%1000000007;
}
int ct,val[maxn<<2],son[maxn<<2][2],w[maxn<<2],sz[maxn<<2];
int new_node(int x){
	int id=++ct;
	val[id]=x;
	son[id][0]=son[id][1]=0;
	sz[id]=1;
	w[id]=_rand();
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
	else x=b,merge(son[b][0],a,son[b][0]);
	update(x);
}
void ins(int &rt,int v){
	int x,y;
	split(rt,x,y,val[v]);
	merge(x,x,v);
	merge(rt,x,y);
}
int xrank(int x,int v){
	if(v>sz[x]) return -1;
	if(v==sz[son[x][0]]+1) return val[x];
	else if(v<=sz[son[x][0]]) return xrank(son[x][0],v);
	else return xrank(son[x][1],v-sz[son[x][0]]-1);
}
int find(int x){
	return rt[x]==x?x:rt[x]=find(rt[x]);
}
void dfs(int x,int &y){		//splitting tree x
	if(!x) return;
	dfs(son[x][0],y);
	dfs(son[x][1],y);
	son[x][0]=son[x][1]=0;
	ins(y,x);	//insert x to tree y
}
int merg(int x,int y){
	if(sz[x]>sz[y]) swap(x,y);	//x->y;
	dfs(x,y);
	return y;
}
int main(){
	read(n),read(m);
	for(int i=1,x;i<=n;i++) read(x),rt[i]=new_node(x),toid[x]=i;
	for(int i=1,x,y;i<=m;i++){
		read(x),read(y);
		if(find(x)!=find(y)){
			int c=merg(rt[x],rt[y]);
			rt[find(x)]=rt[find(y)]=rt[c]=c;
		}
	}
	read(q);
	char op;
	for(int i=1,x,y,kk;i<=q;i++){
		op=nxt_op(); read(x),read(y);
		if(op=='Q') write((kk=xrank(rt[find(x)],y))==-1?-1:toid[kk]),putchar('\n');
		else{
			if(find(x)!=find(y)){
				int c=merg(rt[x],rt[y]);
				rt[find(x)]=rt[find(y)]=rt[c]=c;
			}
		}
	}
	return 0;
}
