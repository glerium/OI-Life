#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,cnt,head[25],od[25],ans,vcnt;
bool v[25];
int flag;
struct Edge{
	int to,nxt;
}a[2507];
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
bool gettt(int *des,int x,int y){
	for(int i=head[x];i;i=a[i].nxt){
		if(a[i].to==od[vcnt+1]&&!v[a[i].to]){
			*des=i;
			return true;
		}
	}
	return false;
}
bool found(int *des,int x){
	for(int i=head[x];i;i=a[i].nxt){
		if(!v[a[i].to]){
			*des=i;
			return true;
		}
	}
	return false;
}
void check(int x){
//	printf("::%d\n",x);
	if(vcnt==n){
//		puts("fff");
		flag=true;
		return;
	}
	for(int i=head[x];i;){
		if(a[i].to==od[vcnt+1]&&!v[a[i].to]){
			v[a[i].to]=true;
//			printf(":: %d->%d\n",x,a[i].to);
			vcnt++;
			check(a[i].to);
			if(flag) return;
			int tmp;
			if(gettt(&tmp,x,od[vcnt+1])) i=tmp;
			else flag=-1;
		}else i=a[i].nxt;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;i++) od[i]=i;
	do{
//		printf("start: ");
//		for(int i=1;i<=n;i++) printf("%d ",od[i]);
//		puts("");
		flag=false;
		memset(v,0,sizeof(v));
		vcnt=1;
		check(od[1]);
		if(flag) ans++;
	}while(next_permutation(od+1,od+1+n));
	printf("%d\n",ans);
	return 0;
}
