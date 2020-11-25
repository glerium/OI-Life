#include <cstdio>
using namespace std;
int n,x,y;
const int mod=998244352;
template<typename T>void read(T&x){
	T v=0; char ch=getchar();
	while(ch>'9'||ch<'0'){ch=getchar();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar();
	x=v*w;return;
}
template<typename T>void write(T x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int powmod(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ans;
}
int main(){
	read(x),read(n);
	for(int i=1;i<=n;i++){
		read(y);
		write(powmod(x,y));
		putchar(' ');
	}
	return 0;
}
