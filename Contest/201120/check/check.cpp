#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
const ll p=998244353;
const double eps=1e-3;
int n,m,a[maxn][maxn],limx,limy,Lg2[maxn];
ll sig2[maxn],fin;
bool t[maxn][maxn][11][11];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
bool check(int i,int j,int x,int y){
	int lim1=Lg2[x],lim2=Lg2[y];
	return (t[i][j][lim1][lim2])&&(t[i+x-(1<<lim1)][j][lim1][lim2])&&
		   (t[i][j+y-(1<<lim2)][lim1][lim2])&&(t[i+x-(1<<lim1)][j+y-(1<<lim2)][lim1][lim2]);
}
int main(){
	freopen("check.in","r",stdin);
	freopen("check.out","w",stdout);
	for(int i=1;i<=1000;i++) Lg2[i]=log2(i+eps);
	read(n),read(m); limx=Lg2[n],limy=Lg2[m];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%1d",&a[i][j]),t[i][j][0][0]=bool(a[i][j]);
	for(int i=1;i<=1000;i++) sig2[i]=(sig2[i-1]+i*i)%p;
	for(int x=0;x<=limx;x++){
		for(int y=0;y<=limy;y++){
			if(!x&&!y) continue;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(x) t[i][j][x][y]|=(t[i][j][x-1][y])&(t[i+(1<<(x-1))][j][x-1][y]);
					if(y) t[i][j][x][y]|=(t[i][j][x][y-1])&(t[i][j+(1<<(y-1))][x][y-1]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!a[i][j]) continue;
			for(int k=1;i+k-1<=n;k++){
				int l=1,r=m-j+1,mid,ans=-1;
				while(l<=r){
					mid=l+r>>1;
					if(check(i,j,k,mid)) ans=mid,l=mid+1;
					else r=mid-1;
				}
				if(ans!=-1) fin=(fin+1ll*k*k*sig2[ans])%p/*,printf("%d %d %d %d\n",i,j,k,ans)*/;
			}
		}
	}
	printf("%lld\n",fin);
 	fclose(stdin);
	fclose(stdout);
	return 0;
}
