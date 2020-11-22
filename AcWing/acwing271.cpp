#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int k,p[10];
int main(){
	while(~scanf("%d",&k)&&k){
		memset(p,0,sizeof(p));
		for(int i=1;i<=k;i++) scanf("%d",&p[i]);
		unsigned f[p[1]+1][p[2]+1][p[3]+1][p[4]+1][p[5]+1];
		memset(f,0,sizeof(f));
		f[0][0][0][0][0]=1;
		for(int a=0;a<=p[1];a++){
			for(int b=0;b<=min(p[2],a);b++){
				for(int c=0;c<=min(p[3],b);c++){
					for(int d=0;d<=min(p[4],c);d++){
						for(int e=0;e<=min(p[5],d);e++){
							if(a) f[a][b][c][d][e]+=f[a-1][b][c][d][e];
							if(b) f[a][b][c][d][e]+=f[a][b-1][c][d][e];
							if(c) f[a][b][c][d][e]+=f[a][b][c-1][d][e];
							if(d) f[a][b][c][d][e]+=f[a][b][c][d-1][e];
							if(e) f[a][b][c][d][e]+=f[a][b][c][d][e-1];
						}
					}
				}
			}
		}
		printf("%lld\n",f[p[1]][p[2]][p[3]][p[4]][p[5]]);
	}
	return 0;
}
