#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e4+10;
int f[maxn][maxn];
char s[maxn];
int dp(int l,int r){
	if(f[l][r]!=-1) return f[l][r];
	if(l>=r) return f[l][r]=0;
	if(s[l]==s[r]) return f[l][r]=dp(l+1,r-1);
	else return f[l][r]=min(dp(l+1,r),dp(l,r-1))+1;
}
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	memset(f,-1,sizeof(f));
	printf("%d\n",dp(1,n));
	return 0;
}
