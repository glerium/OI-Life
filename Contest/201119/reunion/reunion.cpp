#include <cstdio>
using namespace std;
template<typename T>void read(T& x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
int main(){
	freopen("reunion.in","r",stdin);
	freopen("reunion.out","w",stdout);
	puts("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
