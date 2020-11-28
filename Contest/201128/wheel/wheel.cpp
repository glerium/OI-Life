#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m,a[maxn],A,B,P,t[maxn],ct[maxn],ans;
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch)){v=v*10+ch-'0';ch=getchar ();}
	x=v*w; return;
}
void dfs(int x){
	if(x==m+1){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(ct[i]+1<=a[i]){
			ct[i]++;
			dfs(x+1);
			ct[i]--;
		}
	}
}
int main(){
	freopen("wheel.in","r",stdin);
	freopen("wheel.out","w",stdout);
	read(n),read(m),read(a[1]),read(A),read(B),read(P);
	for(int i=2;i<=n;i++) a[i]=(1ll*a[i-1]*A+B)%P+1;
	dfs(1);
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
