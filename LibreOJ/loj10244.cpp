#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxm=15;
const int maxn=2e3+10;
int n,m,a[maxm],b[maxn],sg[maxn];
int gt(int x){
	if(sg[x]!=-1) return sg[x];
	int v[maxn];
	memset(v,0,sizeof(v));
	for(int i=1;i<=m&&x>=b[i];i++){
//		printf("%d: %d\n",x-b[i],gt(x-b[i]));
		v[gt(x-b[i])]=true;
	}
	int kkk=0;
	while(v[kkk]) kkk++;
	return sg[x]=kkk;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	memset(sg,-1,sizeof(sg));
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	int tmpmin=1e5;
	for(int i=1;i<=m;i++) tmpmin=min(tmpmin,b[i]);
	for(int i=0;i<tmpmin;i++) sg[i]=0;
	int ans=0;
	for(int i=1;i<=n;i++) ans^=gt(a[i]);
	puts(ans?"YES":"NO");
	if(ans){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i]>=b[j]&&(ans^gt(a[i]-b[j])^gt(a[i]))==0){
					printf("%d %d\n",i,b[j]);
					return 0;
				}
			}
		}
	}
	return 0;
}
