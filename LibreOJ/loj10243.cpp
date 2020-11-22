#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2007;
const int maxm=6007;
int n,m,k,head[maxn],cnt,t[maxn],out[maxn],sg[maxn];
struct Edge{
	int to,nxt;
}a[maxm<<1];
void add(int x,int y){
	a[++cnt]=(Edge){y,head[x]};
	head[x]=cnt;
}
int gt(int x){
	if(sg[x]!=-1) return sg[x];
	int imact=0;
	for(int i=head[x];i;i=a[i].nxt) imact++;
	bool f[imact+3];
	memset(f,0,sizeof(f));
	for(int i=head[x];i;i=a[i].nxt){
		if(gt(a[i].to)<=imact)
			f[gt(a[i].to)]=1;
	}
	int kkk=0;
	while(f[kkk]) kkk++;
	return sg[x]=kkk;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);out[x]++;
	}
	for(int i=1;i<=k;i++) scanf("%d",&t[i]);
	memset(sg,-1,sizeof(sg));
	for(int i=1;i<=n;i++) if(!out[i]) sg[i]=0;
	int ans=0;
	for(int i=1;i<=k;i++) ans^=gt(t[i]);
	puts(ans?"win":"lose");
	return 0;
}
