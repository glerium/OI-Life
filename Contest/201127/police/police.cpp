#include <bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
int t,n,u,v,to[maxn];
bool vis[maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch)){v=v*10+ch-'0';ch=getchar ();}
	x=v*w; return;
}
void dfs(int x){
	vis[x]=true;
	if(!vis[to[x]]) dfs(to[x]);
}
int main(){
	freopen("police.in","r",stdin); freopen("police.out","w",stdout);
	read(t); while(t--){
		memset(vis,0,sizeof(vis));
		read(n),read(u),read(v);
		bool ans=false;
		for(int i=1;i<=n;i++) {read(to[i]); if(i==u&&to[i]==v) ans=true;}
		dfs(u); ans|=vis[v]&&v==to[to[v]];
		puts(ans?"Yes":"No");
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
