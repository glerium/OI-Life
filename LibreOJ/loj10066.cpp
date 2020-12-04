#include <bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
int n,head[maxn],cnt,fa[maxn];
struct Edge{
	int from,to,dis;
	bool operator<(const Edge& rhs)const{return dis<rhs.dis;}
}a[maxn];
void add(int x,int y,int z){
	a[++cnt]=(Edge){x,y,z};
}
int find(int x){
	return fa[x]==x?x:find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),add(0,i,x);
	for(int i=1,x;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&x);
			if(i>j) add(i,j,x);
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=1;i<=n;i++) fa[i]=i;
	int ct=0,ans=0;
	for(int i=1;i<=cnt;i++){
		if(find(a[i].from)!=find(a[i].to)){
			merge(a[i].from,a[i].to);
			ans+=a[i].dis;
			ct++;
			if(ct==n) break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
