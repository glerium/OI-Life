#include <bits/stdc++.h>
using namespace std;
const int p=1e9+7;
const int maxn=1e6+10;
int n,k,w[maxn],c[maxn],d[maxn],f[11][11][11][11][11][107],pos[10];
long long ans;
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
int dfs(int a1,int a2,int a3,int a4,int a5,int st){
	if(f[a1][a2][a3][a4][a5][st]) return f[a1][a2][a3][a4][a5][st];
	int& fff=f[a1][a2][a3][a4][a5][st];
	if(c[st]==1) a1+=d[st];
	if(c[st]==2) a2+=d[st];
	if(c[st]==3) a3+=d[st];
	if(c[st]==4) a4+=d[st];
	if(c[st]==5) a5+=d[st];
	if(a1>w[1]||a2>w[2]||a3>w[3]||a4>w[4]||a5>w[5]||a1<0||a2<0||a3<0||a4<0||a5<0) return 1;
	return fff=(1+dfs(a1,a2,a3,a4,a5,st==n?1:st+1))%p;
}
void geta(int x){
	if(x==k+1){
		ans+=dfs(pos[1],pos[2],pos[3],pos[4],pos[5],1); ans%=p;
		return;
	}
	for(int i=1;i<=w[x];i++){
		pos[x]=i;
		geta(x+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n),read(k);
	for(int i=1;i<=k;i++) read(w[i]);
	for(int i=k+1;i<=5;i++) w[i]=333;
	for(int i=1;i<=n;i++) read(c[i]),read(d[i]);
	geta(1);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
