#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=207;
int n,m,t[maxn][maxn];
int sg(int x,int y){
	if(t[x][y]!=-1) return t[x][y];
	int f[maxn];
	memset(f,0,sizeof(f));
	for(int i=2;i<=x-2;i++) f[sg(i,y)^sg(x-i,y)]=1;
	for(int i=2;i<=y-2;i++) f[sg(x,i)^sg(x,y-i)]=1;
	int p=0;
	while(f[p]) p++;
	return t[x][y]=p;
}
int main(){
	memset(t,-1,sizeof(t));
	t[2][2]=t[2][3]=t[3][2]=0;
	while(~scanf("%d%d",&n,&m))
		puts(sg(n,m)?"WIN":"LOSE");
	return 0;
}
