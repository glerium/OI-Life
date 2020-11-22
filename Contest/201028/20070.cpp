#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=2e3+10;
int n,m,ans,k;
vector<int> l[maxn],r[maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){v=v*10+ch-'0';ch=getchar();}
	x=v*w;return;
}
bool dfs(int t,int x){
	printf("%d %d\n",t,x);
	if(t>k) return 0;
	if(x==n){
		ans=t;
		return 1;
	}
	for(int i=max(1,x-1);i<=min(n,x+1);i++){
		for(int j=0;j<l[i].size();j++) if(l[i][j]<=t+1&&t+1<=r[i][j]) continue;
		dfs(t+1,i);
	}
	return 1;
}
int main(){
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);
	read(n),read(m);
	for(int i=1,x,y,z;i<=m;i++) read(x),read(y),read(z),l[x].push_back(y),r[x].push_back(z),k=max(k,max(y,z));
	k+=n+1;
	if(dfs(1,1)) printf("%d\n",ans);
	else puts("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
