#include <cstdio>
using namespace std;
const int maxn=1e5+10;
int n,p[maxn],q[maxn],k,a[10][maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
int main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool checkp=true;
	for(int i=1;i<=n;i++) scanf("%d",&p[i]),a[1][i]=p[i],checkp&=(p[i]==i);
	for(int i=1;i<=n;i++) scanf("%d",&q[i]),a[2][i]=q[i];
	if(checkp){
		for(int i=3;i<=6;i++){
			for(int j=1;j<=n;j++){
				a[i][a[i-2][j]]=a[i-1][j];
			}
		}
		for(int i=1;i<=n;i++) printf("%d ",a[(k%6==0)?6:(k%6)][i]);
		puts("");
	}else{
		for(int i=3;i<=k;i++){
			for(int j=1;j<=n;j++){
				a[i%3][a[(i+1)%3][j]]=a[(i+2)%3][j];
			}
		}
		for(int i=1;i<=n;i++) printf("%d ",a[k%3][i]);
		puts("");
//		for(int i=1;i<=n;i++) a[1][i]=p[i],a[2][i]=q[i];
//		for(int i=3;i<=k;i++){
//			for(int j=1;j<=n;j++){
//				a[i][a[i-2][j]]=a[i-1][j];
//			}
//		}
//		for(int i=1;i<=n;i++) printf("%d ",a[k][i]);
//		puts("");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
