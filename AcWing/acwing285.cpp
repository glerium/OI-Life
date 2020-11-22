#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=107;
int n,a[maxn],f[maxn][maxn],g[maxn][maxn],ans[maxn];
char op[maxn];
bool vis[maxn][maxn];
int ta[maxn],tp[maxn];
void mk(int l,int r){
	if(vis[l][r]) return;
	vis[l][r]=true;
	if(l==r) f[l][r]=g[l][r]=ta[l];
	for(int i=l;i<=r-1;i++){
		mk(l,i);mk(i+1,r);
		int x1=f[l][i],y1=g[l][i],
			x2=f[i+1][r],y2=g[i+1][r];
		if(tp[i]=='t'){
			f[l][r]=max(f[l][r],x1+x2);
			g[l][r]=min(g[l][r],y1+y2);
		}else{
			f[l][r]=max(f[l][r],max(x1*x2,y1*y2));
			g[l][r]=min(g[l][r],min(x1*x2,y1*y2));
		}
	}
	return;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>op[i]>>a[i];
	int fin=-55555;
	for(int i=1;i<=n;i++){		//Ã¶¾ÙÉ¾±ß 
		memset(vis,0,sizeof(vis));
		int ct1=0,ct2=0;
		for(int j=i;j<=n;j++) ta[++ct1]=a[j];		//tranferring num & oper
		for(int j=1;j<i;j++) ta[++ct1]=a[j];
		for(int j=i+1;j<=n;j++) tp[++ct2]=op[j];
		for(int j=1;j<=i-1;j++) tp[++ct2]=op[j];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=-500000;
				g[i][j]=500000;
			}
		}
		mk(1,n);
		ans[i]=f[1][n];
		fin=max(fin,ans[i]);
	}
	printf("%d\n",fin);
	for(int i=1;i<=n;i++){
		if(ans[i]==fin)
			printf("%d ",i);
	}
	return 0;
}
