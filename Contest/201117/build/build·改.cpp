#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
const int maxm=4e5+10;
int n,m,q,head[maxn],cnt,fa[maxn];
struct Edge{
	int x,y,v;
	bool operator<(const Edge& rhs)const{return v<rhs.v;}
}a[maxm];
void add(int x,int y,int v){
	a[++cnt]=(Edge){x,y,v};
}
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
void merge(int x,int y){
	fa[get(x)]=get(y);
}
int main(){
	freopen("build.in","r",stdin);
	freopen("build.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1,x,y,v;i<=m;i++){
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v),add(y,x,v);
	}
	sort(a+1,a+1+cnt);
	int lans=0,rans=0,lcnt=0,rcnt=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=cnt;i++){
		if(get(a[i].x)!=get(a[i].y)){
			merge(a[i].x,a[i].y);
			lcnt++;
			lans+=a[i].v;
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=cnt;i>=1;i--){
		if(get(a[i].x)!=get(a[i].y)){
			merge(a[i].x,a[i].y);
			rcnt++;
			rans+=a[i].v;
		}
	}
//	printf("%d %d\n",lans,rans);
	for(int i=1,x;i<=q;i++){
		scanf("%d",&x);
		if(lans<=x&&x<=rans) puts("Yes");
		else puts("No");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
