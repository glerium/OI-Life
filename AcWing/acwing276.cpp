#include <bits/stdc++.h>
using namespace std;
const int maxn=20;
const int maxm=250;
int n,m,q,a[maxn][maxn],f[maxn][maxm][maxn][maxn][2][2],s[maxn][maxm];
struct State{
	int i,s,j,k,x,y;
}pre[maxn][maxm][maxn][maxn][2][2];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]),s[i][j]=s[i][j-1]+a[i][j];
	int ans=0;
	State out=(State){0,0,0,0,0,0};
	for(int i=1;i<=n;i++){		//line i
		for(int k=1;k<=q;k++){	//num cnt
			for(int l=1;l<=m;l++){		//ima left
				for(int r=l;r<=m;r++){	//ima right
					if(k-(r-l+1)<0) continue;
					//toima 0,0
					for(int tl=l;tl<=r;tl++){
						for(int tr=l;tr<=r;tr++){
							if(f[i-1][k-(r-l+1)][tl][tr][0][0]+s[i][r]-s[i][l-1]>f[i][k][l][r][0][0]){
								f[i][k][l][r][0][0]=f[i-1][k-(r-l+1)][tl][tr][0][0]+s[i][r]-s[i][l-1];
								pre[i][k][l][r][0][0]=(State){i-1,k-(r-l+1),tl,tr,0,0};
							}
						}
					}
					//toima 0,1
					for(int tl=l;tl<=r;tl++){
						for(int tr=r;tr<=m;tr++){
							for(int wzl=0;wzl<=1;wzl++){
								if(f[i-1][k-(r-l+1)][tl][tr][0][wzl]+s[i][r]-s[i][l-1]>f[i][k][l][r][0][1]){
									f[i][k][l][r][0][1]=f[i-1][k-(r-l+1)][tl][tr][0][wzl]+s[i][r]-s[i][l-1];
									pre[i][k][l][r][0][1]=(State){i-1,k-(r-l+1),tl,tr,0,wzl};
								}
							}
						}
					}
					//toima 1,0
					for(int tl=1;tl<=l;tl++){
						for(int tr=l;tr<=r;tr++){
							for(int wzl=0;wzl<=1;wzl++){
								if(f[i-1][k-(r-l+1)][tl][tr][wzl][0]+s[i][r]-s[i][l-1]>f[i][k][l][r][1][0]){
									f[i][k][l][r][1][0]=f[i-1][k-(r-l+1)][tl][tr][wzl][0]+s[i][r]-s[i][l-1];
									pre[i][k][l][r][1][0]=(State){i-1,k-(r-l+1),tl,tr,wzl,0};
								}
							}
						}
					}
					//toima 1,1
					for(int tl=1;tl<=l;tl++){
						for(int tr=r;tr<=m;tr++){
							for(int wzl=0;wzl<=1;wzl++){
								for(int wcy=0;wcy<=1;wcy++){
									if(f[i-1][k-(r-l+1)][tl][tr][wzl][wcy]+s[i][r]-s[i][l-1]>f[i][k][l][r][1][1]){
										f[i][k][l][r][1][1]=f[i-1][k-(r-l+1)][tl][tr][wzl][wcy]+s[i][r]-s[i][l-1];
										pre[i][k][l][r][1][1]=(State){i-1,k-(r-l+1),tl,tr,wzl,wcy};
									}
								}
							}
						}
					}
					if(q==k){
						for(int wzl=0;wzl<=1;wzl++){
							for(int wcy=0;wcy<=1;wcy++){
								if(ans<f[i][k][l][r][wzl][wcy]){
									ans=f[i][k][l][r][wzl][wcy];
									out=(State){i,k,l,r,wzl,wcy};
								}
							}
						}
					}
				}
			}
		}
	}
	printf("Oil : %d\n",ans);
	while(out.s){
		for(int i=out.j;i<=out.k;i++)
			printf("%d %d\n",out.i,i);
		out=pre[out.i][out.s][out.j][out.k][out.x][out.y];
	}
	return 0;
}
