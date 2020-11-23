#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=305;
int n;
ll a[maxn],s[maxn],f1[maxn][maxn],f2[maxn][maxn],l1[maxn][maxn],l2[maxn][maxn],r1[maxn][maxn],r2[maxn][maxn],ct[maxn][maxn];
ll bl[50];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
int main(){
	freopen("godluoskyzheng.in","r",stdin);
	freopen("godluoskyzheng.out","w",stdout);
	read(n);
	bool is2=true;
	for(int i=1;i<=n;i++) read(a[i]),is2&=(i==1?a[i]>=1:a[i]>=a[i-1]);
	if(n==1){
		puts("0");
		return 0;
	}
	if(n<=20){
		int maxs=1<<(n-1);
		ll ans=0;
		for(int i=0;i<maxs;i++){
			int ct=0;
			ll s=0,cur=0;
			for(int j=0;j<n;j++){
				s+=a[j+1];
				if(i&(1<<j)){
					bl[++ct]=s;
					s=0;
				}
			}
			bl[++ct]=s;
			for(int j=1;j<ct;j++) cur+=bl[j]*bl[j+1];
			ans=max(ans,cur);
		}
		printf("%lld\n",ans);
	}else if(is2){
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		ll ans=0;
		for(int i=1;i<=n-1;i++)
			ans=max(ans,s[i]*(s[n]-s[i]));
		printf("%lld\n",ans);
	}else{
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		for(int l=1;l<=n;l++){
			for(int i=1,j=i+l-1;i<=n&&j<=n;i++,j++){
				for(int k=i+1;k<j;k++){
					if(f1[i][j]<f1[i][k-1]+r2[i][k-1]*a[k]+f1[k+1][j]+l1[k+1][j]*a[k]){
						f1[i][j]=f1[i][k-1]+r2[i][k-1]*a[k]+f1[k+1][j]+l1[k+1][j]*a[k];
						
					}
					if(f1[i][j]<f1[i][k-1]+l1[i][k-1]*a[k]+f1[k+1][j]+r2[k+1][j]*a[k]){
						f1[i][j]=f1[i][k-1]+l1[i][k-1]*a[k]+f1[k+1][j]+r2[k+1][j]*a[k];
						
					}
					if(f1[i][j]<f1[i][k-1]*a[k]+a[k]*f1[k+1][j]){
						f1[i][j]=f1[i][k-1]*a[k]+a[k]*f1[k+1][j];
						
					}
					
				}
			}
		}
		printf("%lld\n",max(0ll,f1[1][n]));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
