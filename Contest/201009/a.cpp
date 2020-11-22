#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e7+10;
int n,f[maxn];
char s[maxn];
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%s",&n,s+1);
	for(int i=n;i>=1;i--) f[i]=(s[i]>=s[f[i+1]])?i:f[i+1];
	int ans=0;
	for(int i=1;i<=n+1;i=f[i]+1){
		ans++;
		if(i!=1) putchar(s[i-1]);
		if(i==n+1) break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
