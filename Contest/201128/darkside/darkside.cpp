#include <bits/stdc++.h>
using namespace std;
const int maxn=4e3+10;
const int maxm=1e6+10;
int n,a[maxm],b[maxm],f[maxn][maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch)){v=v*10+ch-'0';ch=getchar ();}
	x=v*w; return;
}
int main(){
	freopen("darkside.in","r",stdin);
	freopen("darkside.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(b[i]);
	if(n<=4000){
		for(int i=1;i<=n;i++) f[0][i]=f[i][0]=i;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i-1][j],f[i][j-1])+1;
				if(a[i]!=b[j]) f[i][j]=min(f[i][j],f[i-1][j-1]+1);
			}
		}
		printf("%d\n",f[n][n]);
	}else{
		int isok=0;
		for(int i=1;i<=n;i++){
			if(a[i]==b[i]){
				isok=1;
				break;
			}
		}
		printf("%d\n",n+isok);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
