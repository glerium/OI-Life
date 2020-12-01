#include <bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
int n,m,head[maxn],cnt,out[maxn];
double f[maxn];
struct Edge{
	int to,dis,nxt;
}a[maxn];
void add(int x,int y,int z){
	a[++cnt]=(Edge){y,z,head[x]};
	head[x]=cnt;
}
void dfs(int x){
	if(abs(f[x])>1e-6) return;
	for(int i=head[x];i;i=a[i].nxt){
		dfs(a[i].to);
		f[x]+=f[a[i].to]+a[i].dis;
	}
	if(x!=n) f[x]/=out[x];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z); out[x]++;
	}
	f[n]=0;
	dfs(1);
	printf("%.2lf\n",f[1]);
	return 0;
}
