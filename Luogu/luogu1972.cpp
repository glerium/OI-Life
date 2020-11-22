#include <cstdio>
using namespace std;
const int maxn=1e5+10;
int n,m,a[maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar();
	x=v*w; return;
}
int main(){
	read(n); for(int i=1;i<=n;i++) read(a[i]);
	read(m);
	for(int i=1,x,y;i<=m;i++){
		read(x),read(y);
		
	}
}
