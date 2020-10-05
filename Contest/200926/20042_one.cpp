#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e6+10;
int n,a[maxn],minn[maxn]={100000000},ans[maxn];
template<typename T> void read(T& x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-') w=-1; ch=getchar ();}
	while(ch<='9'&&ch>='0'){v=v*10+ch-'0'; ch=getchar ();}
	x=v*w; return;
}
int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) minn[i]=min(minn[i-1],a[i]);
	for(int i=1;i<=n;i++) ans[i]=a[i]-minn[i];
	int out=0;
	for(int i=1;i<=n;i++) out=max(out,ans[i]);
	printf("%d\n",out);
	return 0;
}
