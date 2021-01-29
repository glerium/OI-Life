#include <bits/stdc++.h>
using namespace std;
const int maxn=55,maxm=407,maxt=820010;
int n,m,a[maxn][maxm],dep[maxm],suc_cnt,ans,ct[maxm];
bool suc[maxn];
struct Op{
	int x,y;
}t[maxt];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){v=v*10+ch-'0';ch=getchar();}
	x=v*w; return;
}
template<typename T>void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]);
	for(int i=1;i<=n;i++) ct[i]=m;
	while(suc_cnt<n){
		memset(dep,0,sizeof(dep));
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dep[a[i][j]]+=m-j;
		int ima=1;
		for(int i=1;i<=n;i++){
			if(suc[i]) continue;
			if(dep[i]<dep[ima]) i=ima;
		}
		if(suc[ima]) break;
		
	}
	write(ans); putchar('\n');
	for(int i=1;i<=ans;i++){
		write(t[i].x), putchar(' ');
		write(t[i].y), putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
