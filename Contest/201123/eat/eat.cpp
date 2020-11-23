#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=2e3+10;
int t,n,k;
ll s[maxn],a[maxn];
bool f[maxn][maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
bool dfs(int l,int r){
//	printf("%d %d: %d\n",l,r,s[r]-s[l]);
	if(f[l][r]) return f[l][r];
	f[l][r]=true;
	if(l-1>=1&&s[r]-s[l-1]>=0) dfs(l-1,r);
	if(r+1<=n&&s[r+1]-s[l]>=0) dfs(l,r+1);
	return f[l][r];
}
int main(){
	freopen("eat.in","r",stdin);
	freopen("eat.out","w",stdout);
	read(t);
	while(t--){
		memset(f,0,sizeof(f));
		read(n),read(k);
		for(int i=1;i<=n;i++) read(a[i]);
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		dfs(k,k);
		puts(f[1][n]?"Yes":"No");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
