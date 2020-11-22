#include <cstdio>
using namespace std;
const int maxn=2e5+10;
int t,n,a[maxn],ct1,ct0;
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++) read(a[i]);
		ct1=ct0=0;
		int a1=0,a2=0;
		for(int i=1;i<=n;i++){
			if(a[i]) ct1++;
			else ct0++;
		}
		int now=0;
		if(ct1) a1^=1,ct1--,now^=1;
		if(ct1) a2^=1,ct1--,now^=1;
		now^=ct0&1; ct0=0;
		for(int i=1;i<=ct1;i++){
			if(now) a2^=1;
			else a1^=1;
			now^=1;
		}
		if(a1>a2) puts("Mitsuha");
		else if(a1<a2) puts("Taki");
		else puts("Draw");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
