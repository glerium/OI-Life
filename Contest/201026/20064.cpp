#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,m,a[maxn],b[maxn],l[maxn],r[maxn],pft[25],f[maxn][20][10];	//on f[i][j]: a[k]->a[f[i][j][k]]
template<typename T>void read(T& x){
	T v=0,w=1;char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch<='9'&&ch>='0'){v=v*10+ch-'0';ch=getchar ();}
	x=v*w; return;
}
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++) read(a[i]),read(b[i]);
	
	pft[0]=1;		//pow 2
	for(int i=1;i<=18;i++) pft[i]=pft[i-1]*2;
	
	const int ori[10]={0,1,2,3,4,5,6,7,8,9};	//condition where operated once
	for(int i=1;i<=n;i++){
		memcpy(&f[i][0],ori,sizeof(ori));
		swap(f[i][0][a[i]],f[i][0][b[i]]);
	}
	
	int maxlog=log2(n);		//initialize
	for(int i=1;i<=maxlog;i++){		//st table
		for(int j=1;j<=n&&j+pft[i-1]<=n;j++){
			int* fr1=f[j][i-1],*fr2=f[j+pft[i-1]][i-1];
			for(int k=0;k<=9;k++) f[j][i][k]=fr1[fr2[k]];
		}
	}
	
	for(int i=1;i<=m;i++){	//query
		int l,r;read(l),read(r);
		int stt[10],ima=l;
		memcpy(stt,ori,sizeof(stt));
		for(int j=16;j>=0;j--){
			if(ima+pft[j]-1<=r){
				int* nxt=f[ima][j];
				int nw[10],to[10];
				for(int k=0;k<=9;k++) nw[k]=stt[nxt[k]];
				for(int k=0;k<=9;k++) stt[k]=nw[k];
				ima+=pft[j];
			}
		}
		for(int j=0;j<=9;j++){
			printf("%d",stt[j]);
			if(j^9) printf(" ");
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
