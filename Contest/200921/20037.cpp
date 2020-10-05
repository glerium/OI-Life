#include <cstdio>
#include <algorithm>
using namespace std;
template<typename T> void read(T& x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-') w=-1; ch=getchar ();}
	while(ch<='9'&&ch>='0'){v=v*10+ch-'0'; ch=getchar ();}
	x=v*w; return;
}
int n,m,t;
int main(){
	read(n),read(m),read(t);
	printf("%lld\n",1ll*2*n*m+1);
	return 0;
}
